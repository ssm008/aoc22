#!/usr/bin/env bash

set -o errexit
set -o nounset 

if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo 'Usage: ./aoc.sh command arguments
Commands:
	create <day>          - creates input, test and code for <day>
	test <day>            - compiles and run day <day> code with test input
	run <day>             - compiles and run day <day> code with real input
	profile <day> <input> - compiles and profiles day <day> code against <input>
'
fi

SRC_BASE_DIR="$(dirname "$(readlink -f "$0")")"

day="${2}"

create_day() {
	touch "${SRC_BASE_DIR}"/input/day"${day}".test
	touch "${SRC_BASE_DIR}"/input/day"${day}".input
	cp "${SRC_BASE_DIR}"/src/day_template.c  "${SRC_BASE_DIR}"/src/day"${day}".c
	sed -i "s/Day #/Day ${day}/" "${SRC_BASE_DIR}"/src/day"${day}".c
}

test_day() {
	clang -g "${SRC_BASE_DIR}"/src/day"${day}".c -o "${SRC_BASE_DIR}"/bin/day"${day}"
	"${SRC_BASE_DIR}"/bin/day"${day}" "${SRC_BASE_DIR}"/input/day"${day}".test
}

run_day() {
	clang -O3 "${SRC_BASE_DIR}"/src/day"${day}".c -o "${SRC_BASE_DIR}"/bin/day"${day}"
	"${SRC_BASE_DIR}"/bin/day"${day}" "${SRC_BASE_DIR}"/input/day"${day}".input
}

profile_day() {
	local inputtype="${3}"
	clang -g -O3 "${SRC_BASE_DIR}"/src/day"${day}".c -o "${SRC_BASE_DIR}"/bin/day"${day}"
	valgrind --tool=cachegrind --cachegrind-out-file="${SRC_BASE_DIR}"/bin/day"${day}".cachegrind "${SRC_BASE_DIR}"/bin/day"${day}" "${SRC_BASE_DIR}"/input/day"${day}"."${inputtype}"
	cg_annotate "${SRC_BASE_DIR}"/bin/day"${day}".cachegrind
	#Maybe add some other metrics. perf would have been nice but I'm running on WSL2
}

mkdir -p "${SRC_BASE_DIR}"/bin
mkdir -p "${SRC_BASE_DIR}"/src
mkdir -p "${SRC_BASE_DIR}"/input

case "${1}" in
	create)
		create_day "$@"
		;;
	test)
		test_day "$@"
		;;
	run)
		run_day "$@"
		;;
	profile)
		profile_day "$@"
		;;
	*)
		;;
esac

