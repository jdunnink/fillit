#!/usr/bin/env node
const fs = require("fs");
const path = require("path");
const child_process = require('child_process');

const generate = (tetroset, amt) =>
	(new Array(amt).fill(0)).map((i,v) =>
		tetroset[Math.floor(Math.random() * tetroset.length)]).join("\n");

const genDiff = diff => generate(tetroset, diff);

const tetroset = [
	`....
	 ###.
	 .#..
	 ....`,
	`....
	 ####
	 ....
	 ....`,
	`###.
	 ..#.
	 ....
	 ....`,
	`....
	 ...#
	 ..##
	 ..#.`,
	`....
	 .##.
	 .##.
	 ....`,
	`##..
	 .#..
	 .#..
	 ....`,
	`....
	 ....
	 ...#
	 .###`
].map(set => set.replace(/[\t ]/g, "") + '\n');

const colors = {
	red:       '\x1b[31m',
	cyan:      '\x1b[36m',
	green:     '\x1b[32m',
	reset:     '\x1b[0m',
	bold:      '\x1b[1m',
	underline: '\u001b[4m',
}



const run = (name) => new Promise((resolve, reject) => {
	const before = new Date().valueOf();
	child_process.exec(`${name} temp`, (err, stdout) => {
		if (stdout.trim() == 'error')
			reject(err);
		const after = new Date().valueOf();
		const delta = after - before;
		resolve({ name, stdout, delta });
	});
});

let stats = Array(process.argv.length - 3).fill({ avg: 0, highest: 0 });
let count = 0;

const main = () => {
	const diff = parseInt(process.argv[2], 10);
	const testCase = genDiff(diff);
	fs.writeFile("temp", testCase, async () => {
		const promises = process.argv.slice(3).map(run);
		const fillits = await Promise.all(promises);
		count++;
		stats = stats.map(({ avg, highest }, index) => {
			const { delta } = fillits[index];
			return {
				avg: (avg * (count - 1) + delta) / count,
				highest: highest > delta ? highest : delta,
				...fillits[index],
			};
		});
		const {allEqual} = stats
			.map(v => v.stdout)
			.reduce(({allEqual, previous}, v) => ({allEqual: allEqual && v == previous, previous: v}), {allEqual: true, previous: stats[0].stdout});
		if (!allEqual)
		{
				console.log();
				console.log("Oh no! The outputs didn't match!");
				const filename = path.normalize(`no-match/${Date.now()}.fillit`);
				fs.writeFile(filename, testCase, () => {});
				console.log(`Input stored in ${colors.green + filename + colors.reset}`);
		}
		const wasSlow = stats.filter(({ delta, avg }) => delta > avg * 15);
		if (wasSlow.length > 0) {
			console.log();
		}
		wasSlow.forEach(({ name, delta, stdout }) => {
			const filename = path.normalize(`hard_fillits/${name}-${count}-${delta}.fillit`);
			fs.writeFile(filename, testCase, () => {});
			console.log(`${colors.green + name + colors.reset} was slow, they took ${colors.cyan + delta + colors.reset}ms`);
			console.log(`Result: \n${stdout}`);
			console.log(`Input stored in ${colors.green + filename + colors.reset}`);
		});
		const formatted = stats
			.slice()
			.sort((a, b) => a.avg - b.avg)
			.map(({avg, highest, name}) =>
			`<${colors.green + name + colors.reset}: avg ${colors.cyan + Math.floor(avg) + colors.reset}ms>`)
			.join(", ");
		process.stdout.write(`\r${colors.bold}Running benchmark${colors.reset} [# of tetros: ${diff}] ${formatted}           `);
		main();
	});
}

main();
