#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue
sys.setrecursionlimit(1000000)
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7

n, t = map(int, input().split())
a = []
for i in range(n):
    si, di, = map(int, input().split())
    ti = math.ceil((t-si)/di)*di + si
    a.append(ti)

indx = 1
ans = a[0]
for i in range(n):
    if a[i] < ans:
        ans = a[i]
        indx = i+1
print(indx)
