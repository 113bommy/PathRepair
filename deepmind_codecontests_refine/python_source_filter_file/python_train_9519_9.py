#import sys
#sys.stdin = open('input.txt','r')
c, d = map(int, input().split())
n, m = map(int, input().split())
k = int(input())
L = 10001
for f in range(m + 1):
	for g in range(n * m + 1):
		if f * n * c + g * d + k >= n * m:
			L = min(L, f * c + g * d)
print(L)