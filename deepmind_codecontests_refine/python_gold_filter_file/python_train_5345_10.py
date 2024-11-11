#!/usr/bin/env python3
import sys

if __name__ == "__main__":
	s1 = sys.stdin.readline()[:-1]
	s2 = sys.stdin.readline()[:-1]
	a1 = {}
	a2 = {}
	if len(s1) != len(s2):
		print("NO")
	else:
		count = 0
		for i in range(len(s1)):
			if s1[i] not in a1:
				a1[s1[i]] = 0
			a1[s1[i]] += 1
			if s2[i] not in a2:
				a2[s2[i]] = 0
			a2[s2[i]] += 1
			if s1[i] != s2[i]:
				count += 1
			if count > 2:
				break
		if a1 == a2 and count <= 2:
			print("YES")
		else:
			print("NO")
