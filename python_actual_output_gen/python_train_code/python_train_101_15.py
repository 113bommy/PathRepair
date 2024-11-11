#!/usr/bin/python3

s = input().strip()
t = "keyence"
for x in range(0,len(t)+1):
	if s.startswith(t[x:]) and s.endswith(t[:x]):
		print("YES")
		exit(0)

print("NO")