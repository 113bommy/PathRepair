
import random
import sys
from sys import stdin

def popcnt(x):
    ret = 0
    while x > 0:
        ret += x % 2
        x //= 2
    return ret

n,m,p = map(int,stdin.readline().split())

s = [stdin.readline()[:-1] for i in range(n)]

ans = 0
anslis = []

for loop in range(30):

    v = random.randint(0,n-1)
    
    vbits = []
    for i in range(m):
        if s[v][i] == "1":
            vbits.append(i)

    dp = [0] * (2**len(vbits))
    vbits.reverse()

    for i in range(n):
        now = 0
        for j in vbits:
            now *= 2
            if s[i][j] == "1":
                now += 1

        dp[now] += 1

    vbits.reverse()
    #print (v,dp)

    for j in range(len(vbits)):
        for i in range(len(dp)):
            
            if i & 2**j == 0:
                dp[i] += dp[i | 2**j]

    #print (v,dp)

    for i in range(len(dp)):
        if dp[i] >= (n+1)//2:
            pc = popcnt(i)

            if ans < pc:
                #print ("change!")
                ans = pc
                anslis = [0] * m
                for j in range(len(vbits)):
                    if 2**j & i > 0:
                        anslis[vbits[j]] = 1

print ("".join(map(str,anslis)))
