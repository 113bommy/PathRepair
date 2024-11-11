import math
import numpy as np

N, K = map(int,input().split())
P = list(map(int,input().split()))
C = list(map(int,input().split()))
#for i in range(len(P)): #Pの中身は次の動く先の位置なのでデクリメントする
#    P[i] -= 1

ans = -99999999999999

for i in range(N):
    x = i
    total = 0
    s=[]
    while(1):#サイクルごとに長さをまず求める，
        x = P[x]-1
        s.append(C[x])
        total += C[x]
        if x == i:
            break
    l = len(s)#サイクルの長さ
    t = 0
    for i in range(l):#サイクルの中でどこで終わるのがベストか探す
        t += s[i]
        if i+1> K:#Kがサイクルより短かったらそこで終わる
            break
        now = t
        if total > 0:
            cycle = int((K-i-1)/l)
            now += total*cycle

        ans = max(ans, now)

print(ans)
