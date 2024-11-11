#!/usr/bin/python3
N = int(input())
l = [1 for x in range(N+1)]
m = [1 for x in range(N+1)]
usr_input = input().split()
ans = 1
for x in range(N):
	m[int(usr_input[x])] = x + 1
for x in range(2,N+1):
	if(m[x] > m[x-1]):
		l[x] += l[x-1]
	if(l[x] > ans):
		ans = l[x]
print(N-ans)

