import {
  version,
  version_string,
} from "./build/libqu.so";

console.log("version hex=", version());
console.log("version string=", version_string());

