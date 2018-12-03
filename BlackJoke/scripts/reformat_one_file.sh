#!/bin/bash

readonly scriptDir=$(dirname $0)

set -euo pipefail

readonly VERSION="0.64"

function main
{
  if [ "$1" = "--check-version" ] ; then
    checkVersion
    exit 0
  fi

  local readonly f="$1"

  if ! uncrustify -c $scriptDir/uncrustify.cfg -f "$f" -o "$f.tmp" -q ; then
	  echo "Warning: failed to reformat '$f'" >&2
	  exit 0
  fi

  if ! diff -Naur "$f" "$f.tmp" ; then
    echo "Formatted $f"
    mv "$f.tmp" "$f"
  else
    rm "$f.tmp"
  fi
}

function checkVersion
{
  local ver=$(uncrustify --version)
  if [ ! "$ver" = "uncrustify $VERSION" ] ; then
    echo "uncrustify (version $VERSION) was not found"
    exit 255
  fi
}

main "$@"

