'use strict';

const addon = require('bindings')('addon');

let obj = new addon.Test();

console.log(obj.name());

obj.age = 1;
console.log(obj.age);
