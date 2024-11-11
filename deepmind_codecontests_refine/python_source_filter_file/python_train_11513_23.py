#####--------------Template Begin-------------------####
import math
import sys
#input = sys.stdin.readline
def ri(): #Regular input
	return input()
def ii(): #integer input
	return int(input())
def li(): #list input
	return input().split()
def mi(): #map input
	return list(map(int, input().split()))
#####---------------Template Ends-------------------######
n, k=mi()
r=n-k
ans=""
a="abcdefghijklmnopqrstuvwxyz"
for i in range(k):
	ans+=a[i]

for i in range(r):
	ans+=a[i]
print(ans)