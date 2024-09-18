import {
  version,
  version_string,
  run,
  idle_test,
} from "./build/libqu.so";

console.log("version hex=", version());
console.log("version string=", version_string());

console.log('idling...')

let i
idle_test(() => {
  console.log('done');
})

run()
console.log('stopped')
