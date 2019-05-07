open SimpleServer;
open Sys;
open Unix;

let args = Sys.argv;
let client = () => {
  if (Array.length(Sys.argv) < 3) {
    print_endline("Usage: client <host> <port>");
    exit(2);
  };
  let serverName = Sys.argv[1];
  let portNumber = Pervasives.int_of_string(Sys.argv[2]);
  let serverAbbr =
    try (gethostbyname(serverName).h_addr_list[0]) {
    | Not_found =>
      print_endline(serverName ++ ": Host not found");
      exit(2);
    };
  let sock = socket(PF_INET, SOCK_STREAM, 0);
  connect(sock, ADDR_INET(serverAbbr, portNumber));
  switch (fork()) {
  | 0 =>
    Util.retransmit(stdin, sock);
    shutdown(sock, SHUTDOWN_SEND);
    exit(0);
  | _ => 
    Util.retransmit(stdin, sock);
    close(stdout);
    wait();
  };
  ();
};

handle_unix_error(client, ());