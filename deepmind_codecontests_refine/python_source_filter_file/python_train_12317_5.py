#import sys
#input = sys.stdin.readline()

import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


M = 998244353 


m, n = map(int,input().split())
if m==1 and n==1:
    print(0)
    exit()



dp = [0]*(max(m,n))
dp[1] = 1
for i in range(2,len(dp)):
    dp[i] = dp[i-1]+2*dp[i-2]+pow(2,i-1,M)
    dp[i] = dp[i]%M
#print(dp)

if m*n>100000:
    print(0)
    exit()


tot = 0
matrix = []
for i in range(m):
    s = input()
#    print(s)
    matrix.append(s)
    for j in range(n):
        if matrix[i][j]==ord('o'):   tot += 1



if m*n>100000:
    print(0)
    exit()

verb = [[] for i in range(m)]
for i in range(m):
    temp = 0
    for j in range(n):
        if matrix[i][j]==ord('o'):
            temp += 1
        else:
            verb[i].append(temp)
            temp = 0
    verb[i].append(temp)



horb = [[] for j in range(n)]

for j in range(n):
    temp = 0
    for i in range(m):
        if matrix[i][j]==ord('o'):
            temp += 1
        else:
            horb[j].append(temp)
            temp = 0
    horb[j].append(temp)


#print(verb)
#print(horb)

ans = 0

for i in range(m):
    for ele in verb[i]:
        if ele<2: continue
        ans += dp[ele-1]*pow(2,tot-ele,M)
        ans = ans%M

for j in range(n):
    for ele in horb[j]:
        if ele<2: continue
        ans += dp[ele-1]*pow(2,tot-ele,M)
        ans = ans%M

print(ans)


 

