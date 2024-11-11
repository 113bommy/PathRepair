#####--------------Template Begin-------------------####
import math
import sys
#input = sys.stdin.readline
def i(): #Regular input
	return input()
def ii(): #integer input
	return int(input())
def li(): #list input
	return input().split()
def mi(): #map input
	return list(map(int, input().split()))
#####---------------Template Ends-------------------######
n,t,k,d=mi()
c=(math.floor(d/t)+1)*k
print(c)
if c>=n:
	print("NO")
else:
	print("YES")