'use strict';

const addon = require('./build/Release/addon');

console.log(addon.hello());
console.log(addon.add(1, 2));
console.log(addon.pid());

// console.time('t1');
// for (let i = 0; i < 10000000; i ++) {
//   addon.time()
// }
// console.timeEnd('t1');
//
// console.time('t2');
// for (let i = 0; i < 10000000; i ++) {
//   Date.now();
// }
// console.timeEnd('t2');

addon.callback(msg => console.log(msg));
