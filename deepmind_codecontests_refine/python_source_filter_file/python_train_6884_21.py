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

first = s.find("[",0,len(s))
second = s.find(":",first,len(s))
fourth = s.rfind("]")
third = s.rfind(":",second,len(s))

if first == -1 or second == -1 or third == -1 or fourth == -1:
	print(-1)
	sys.exit()

if first < second < third < fourth:
	counter = 0
	for i in range(second,third):
		if s[i] == "|":
			counter += 1

	print(counter+4)
else:
	print(-1)
