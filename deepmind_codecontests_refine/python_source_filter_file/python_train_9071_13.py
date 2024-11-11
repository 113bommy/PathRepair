#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7

def solve(x):
    odev = [0, 0]
    y = 0
    for i in range(20):
        a = 1<<i
        if y+a > x:
            odev[i&1] += x-y
            break
        odev[i&1] += a
        y += a

    ans = ((odev[0]*odev[0])%MOD+((odev[1]+1)*odev[1])%MOD)%MOD
    return ans

l, r = map(int, input().split())
print((MOD+solve(r)-solve(l-1))%MOD)