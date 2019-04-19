open Http;

let server =
  createServer((~request, ~response) => {
    switch (ClientRequest.getMethod(request)) {
    | `GET => print_string("GET money, GET paid")
    | `POST => print_string("POSTman Pat")
    | `PUT => print_string("PUTting the tee-pee in HTTP")
    | _ => print_string("We don't accept other methods...")
    };

    ServerResponse.(
      response
      |> setStatusCode(418)
      |> setHeader("x-reason", "reason-ml")
      |> write("Hello, world! I am a teapot!")
      |> write("UmVhc29uTUwgaXMgcHJldHR5IGdyZWF0IQ==", ~encoding=`base64)
      |> end_
    );
  });

Server.(server |> listen(~port=3000));