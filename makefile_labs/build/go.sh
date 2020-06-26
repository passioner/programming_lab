#!/bin/bash

export PROJECT_NAME=$1

cp build/Makefile .

make clean

date=`date +%Y%m%d%H%M%S`

log_dir=logs
if [ ! -d "$log_dir" ]; then
	mkdir -p "$log_dir"
fi

logfile=$log_dir/logs-$date.txt

make 2>&1 | tee $logfile
