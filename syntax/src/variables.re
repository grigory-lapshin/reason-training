type account =
  | None
  | Instagram(string)
  | Facebook(string, int);

let myAccount = Facebook("name", 22);
let friendAccount = Instagram("name");

let greeting =
  switch (myAccount) {
  | Facebook(name, age) =>
    "Hi " ++ name ++ ", you're " ++ string_of_int(age) ++ "-year-old."
  | Instagram(name) => "Hello " ++ name ++ "!"
  | None => "Hola!"
  };