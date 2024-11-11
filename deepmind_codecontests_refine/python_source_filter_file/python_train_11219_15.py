import math
import sys
import collections
import bisect

#sys.setrecursionlimit(1000000000)

input = sys.stdin.readline
flush = sys.stdout.flush

readint    =lambda: int(input())
readintm   =lambda: map(int,input().strip().split())
readintl   =lambda: list(map(int,input().strip().split()))

readfloatm =lambda: map(float,input().strip().split())
readfloatl =lambda: list(map(float,input().strip().split()))

readstr    =lambda: input().strip()
readstrl   =lambda: list(input().strip())

join       =lambda x,l: x.join(map(str,l))
print      =lambda *x: sys.stdout.write(" ".join(map(str,x))+'\n')
printl	   =lambda l: sys.stdout.write(" ".join(map(str,l))+'\n')

ceil       =lambda x,y: (x+y-1)//y
mod        =1000000007

# START HERE

n = readint()
a = readintl()
if n == 1 or (len(a) == 2 and a[0] == a[1]):
	print(-1)
else:
	print(1)
	print(a.index(min(a)))
