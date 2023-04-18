#!/bin/bash
function ProgressBar {
	let _progress=(${1}*100/${2}*100)/100
	let _done=(${_progress}*4)/10
	let _left=40-$_done
	_done=$(printf "%${_done}s")
	_left=$(printf "%${_left}s")
	printf "\rProgress : [${_done// /#}${_left// /-}] ${_progress}%%"

}

_start=1

_end=100

for number in $(seq ${_start} ${_end})
do
	sleep 0.01
	ProgressBar ${number} ${_end}
done
printf "\n\n"
