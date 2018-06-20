let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let httpLink = token =>
  ApolloLinks.createHttpLink(
    ~uri="https://api.github.com/graphql",
    ~headers=
      Js.Json.object_(
        Js.Dict.fromList([
          ("Authorization", Js.Json.string("bearer " ++ token)),
        ]),
      ),
    (),
  );

let instance = token =>
  ReasonApollo.createApolloClient(
    ~link=httpLink(token),
    ~cache=inMemoryCache,
    (),
  );