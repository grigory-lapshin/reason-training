// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");

var myAccount = /* Facebook */Block.__(1, [
    "name",
    22
  ]);

var greeting;

greeting = typeof myAccount === "number" ? "Hola!" : (
    myAccount.tag ? "Hi name, you're " + (String(22) + "-year-old.") : "Hello name!"
  );

var friendAccount = /* Instagram */Block.__(0, ["name"]);

exports.myAccount = myAccount;
exports.friendAccount = friendAccount;
exports.greeting = greeting;
/* greeting Not a pure module */
