#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

n = int(input())
nx = 1
nc = n
while nc >= 10:
    nx *= 10
    nc //= 10
nx *= nc+1
print(nx-n)