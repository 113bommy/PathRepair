#!/usr/bin/python3

N = int(input())
sk = sorted([int(x) for x in input().split()])
ats =  (sk[N-1] - sk[0])*(sk[2*N - 1] - sk[N])
for i in range(1, N//2):
	ats = min(ats, (sk[N-1] - sk[0])*(sk[i + N//2 - 1] - sk[i]))

print(ats)