import {
  version,
  version_string,
  run,
  idle_test,
} from "./build/libqu.so";

console.log("version hex=", version());
console.log("version string=", version_string());

console.log('idling...')
idle_test()

run()
console.log('stopped')
