import sys
import math

def read_int():
	return int(input().strip())

def read_int_list():
	return list(map(int,input().strip().split()))

def read_string():
	return input().strip()

def read_string_list(delim=" "):
	return input().strip().split(delim)

###### Author : Samir Vyas #######
###### Write Code Below    #######

s = read_string()

state = 0

for _s in s:
	if _s == "1":
		if state == 0:
			print(4,3)
			state = 2
		elif state == 1:
			print(4,3)
			state = 3
		elif state == 2:
			print(4,1)
			state = 0
		else:
			print(4,1)
			state = 1

	else:
		if state == 0:
			print(1,1)
			state = 1
		elif state == 1:
			print(3,1)
			state = 0
		elif state == 2:
			print(1,1)
			state = 3
		else:
			print(3,1)
			state = 2





