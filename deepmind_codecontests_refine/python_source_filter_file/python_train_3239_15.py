from sys import stdin,stdout
from collections import Counter
def ai(): return list(map(int,input().split()))
def ei(): return map(int,input().split())
def ip(): return  int(stdin.readline())
def op(ans): return stdout.write(str(ans) + '\n') 

n,m = ei()
min = max(0,n-2*m)
k = 0
while k*(k-1) <= 2*m:k+=1
print(min,n-k)