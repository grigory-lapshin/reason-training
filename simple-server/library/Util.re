open Unix;

let retransmit = (fdin, fdout) => {
  let bufferSize = 4096;
  let buffer = Bytes.create(bufferSize);
  let rec copy = () =>
    switch (read(fdin, buffer, 0, bufferSize)) {
    | 0 => ()
    | n =>
      ignore(write(fdout, buffer, 0, n));
      copy();
    };
  copy();
  ();
};