#!/bin/bash

readonly scriptDir=$(dirname $0)

set -euo pipefail

function main
{
  echo "Reformatting"
  if ! $scriptDir/reformat_one_file.sh --check-version ; then
    echo "Uncrustify not found, skipping reformatting" >&2
    exit 0
  fi

  list_files | xargs -P`nproc` -L1 $scriptDir/reformat_one_file.sh
}

function list_files
{
  find . -size -1024k \( -name "*.cpp" -or -name "*.h" -or -name "*.c" \) | remove_3rd_party_files
}

function remove_3rd_party_files
{
  safeGrep -v "scripts" |
  safeGrep -v "bin"
}

function safeGrep
{
  grep "$@" || true
}

main "$@"

