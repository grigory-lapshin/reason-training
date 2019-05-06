# simple-server


[![CircleCI](https://circleci.com/gh/yourgithubhandle/simple-server/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/simple-server/tree/master)


**Contains the following libraries and executables:**

```
simple-server@0.0.0
│
├─test/
│   name:    TestSimpleServer.exe
│   main:    TestSimpleServer
│   require: simple-server.lib
│
├─library/
│   library name: simple-server.lib
│   namespace:    SimpleServer
│   require:
│
└─executable/
    name:    SimpleServerApp.exe
    main:    SimpleServerApp
    require: simple-server.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x SimpleServerApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
