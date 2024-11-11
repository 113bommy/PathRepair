from sys import stdin,stdout
from collections import Counter
from math import ceil
from bisect import bisect_left 
from bisect import bisect_right
import math

def ai(): return list(map(int, stdin.readline().split()))
def ei(): return map(int, stdin.readline().split())
def ip(): return  int(stdin.readline().strip())
def op(ans): return stdout.write(str(ans) + '\n')

n,m = ei()
if m==0:
	exit(print('YES'))
dirty = ai()
dirty.sort()
check = 0
if 1 in dirty or n in dirty:
	exit(print('NO'))
for i in range(m-1):
	if abs(dirty[i]-dirty[i+1]) == 1:
		check += 1
	else:
		check == 0
	if check == 2:
		break
if check == 2:
	print('NO')
else:
	print('YES')
