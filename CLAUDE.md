- Please never tell me to go try something again, this project is about reverse engineering the firmware, NOT manual testing.
- docs/common_parameters.json contains a reverse engineered set of calterm parameters from e2m files, reference it for parameter names and descriptions
  * **WARNING**: Memory addresses in common_parameters.json may be INCORRECT - they were extracted from e2m files and have not been verified against the actual firmware
  * One goal of this reverse engineering effort is to verify these addresses or identify which ones are wrong
  * When you find a verified address mapping, note it in the CSV comment field
- NEVER make assumptions, ZERO acceptions! If definitive proof isn't available, ask the user for more data!
- the playbook should only contain steps the user should take to replay. It should NOT contain findings, notes, todo's or anything else ZERO EXCEPTIONS
- always use decimal in variable and function names to keep them human readable