open Sys;
// open Unix;

let echo = () => {
  let len = Array.length(Sys.argv);
  if (len > 1) {
    // print_endline(Sys.argv[0]);
    Array.iter(
      a => {
        print_string(a);
        print_char(' ');
      },
      Array.sub(Sys.argv, 1, len - 1),
    );
    print_newline();
  };
  ();
};
echo();