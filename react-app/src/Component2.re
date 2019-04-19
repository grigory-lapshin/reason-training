/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

let rString = string => ReasonReact.string(string);

module Styles = {
  open Css;
  let actionButton = disabled =>
    style([
      background(disabled ? darkgray : white),
      color(red),
      fontSize(em(2.9)),
      border(px(1), solid, black),
      borderRadius(px(3)),
    ]);
};

module ButtonT = {
  let component = ReasonReact.statelessComponent("ButtonT");
  let make = (~onClick, children) => {
    ...component,
    render: _self => {
      <button className={Styles.actionButton(false)} onClick>
        {ReasonReact.array(children)}
      </button>;
    },
  };
};

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
let make = (~greeting, ~onClick=?, _children) => {
  /* spread the other default fields of component here and override a few */
  ...component,

  initialState: () => {count: 0, show: true},

  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },

  render: self => {
    let {count} = self.state;
    let message =
      "You've clicked this " ++ string_of_int(count) ++ " times(s)";
    <div>
      <ButtonT onClick={_event => self.send(Click)}>
        {rString(message)}
      </ButtonT>
      <button onClick={_event => self.send(Toggle)}>
        {rString("Toggle greeting")}
      </button>
      {self.state.show ? ReasonReact.string(greeting) : ReasonReact.null}
    </div>;
  },
};