module GetRepos = [%graphql
  {|
    query {
      viewer {
       id
      }
    }
  |}
];

module GetReposQuery = ReasonApollo.CreateQuery(GetRepos);

/* This is the basic component. */
let component = ReasonReact.statelessComponent("Page");

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = _children => {
  /* spread the other default fields of component here and override a few */
  ...component,
  render: _self => {
    let reposQuery = GetRepos.make();
    <GetReposQuery variables=reposQuery##variables>
      ...(_ => <div />)
    </GetReposQuery>;
  },
};