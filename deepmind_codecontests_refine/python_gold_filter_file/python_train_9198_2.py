from collections import *
import sys  
input=sys.stdin.readline

# "". join(strings)  
    
def ri():
    return int(input())
 
def rl():
    return list(map(int, input().split()))

def getKthBit(n, k):
    return (n & (1 << (k - 1))) >> (k - 1)
    

n, K = rl()
aa = rl()

aa.sort()
for i in range(n + 1):
	if K == 0:
		break
	smalls = aa[:n - i]
	bigs = aa[n-i:]
	# if bigs:
	# 	print(len(bigs), " ".join([str(x) for x in bigs]))
	# 	K -= 1
	for small in smalls:
		print(len(bigs)  + 1, " ".join([str(x) for x in bigs]), small)
		K -= 1
		if K == 0:
			break









