#! /usr/bin/env python3
n = int(input())
way = ["/"]
for i in range(0,n):
	command = input().split()
	if command[0] == "pwd":
		print("".join(way))
	else:
		path = command[1].split('/')
		if path[0] == "":
			way = ['/']
			del path[0]
			if command[1] != '/':
				for i in path:
					if (i == ".."):
						way.pop()
					else:
						way.append(i+"/")
		