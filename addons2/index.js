'use strict';

const main = require('bindings')('main');

// main((msg, num) => {
//   console.log(msg, num)
// }, [1, 2, 3, 4]);

let arr = [];

for (let i = 0; i < 1000; i ++) {
  arr.push(Math.round(Math.random() * 100));
}

console.time('t1');
for (let i = 0; i < 1000; i ++) {
  main.sort.apply(null, arr);
}
console.timeEnd('t1');

console.time('t2');
for (let i = 0; i < 1000; i ++) {
  arr.sort((a, b) => a - b);
}
console.timeEnd('t2');
