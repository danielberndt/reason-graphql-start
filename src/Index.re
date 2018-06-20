/* ReactDOMRe.renderToElementWithId(<Component1 message="Hello!" />, "index1"); */

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=(Client.instance("YOUR TOKEN"))>
    <h1> (ReasonReact.string("Goals 1")) </h1>
    <SortedRepos />
  </ReasonApollo.Provider>,
  "main",
);