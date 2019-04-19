type person = {
  age: int,
  name: string,
};
let person = {age: 10, name: "allan"};
let parseData = (p: person) => p.age;
let validateAge = age => age > 122 ? "you can't" : "sorry";

validateAge(parseData(person));

let res = person->parseData->validateAge;