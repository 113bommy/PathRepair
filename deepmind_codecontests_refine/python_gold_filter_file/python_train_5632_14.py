#!/usr/bin/python3

from sys import stdin, stdout
import sys
# N, M = int(x) for x in stdin.readline().split()
N, M = [int(x) for x in input().split(' ')]

sk = [0]*101
for x in stdin.readline().split():
	sk[int(x)] += 1


for i in range(M//N+1, 0, -1):
	count = 0
	for j in range(101):
		count += sk[j]//i
	if count >= N:
		print(i)
		exit(0)

print(0)