'''
Created on May 25, 2016

@author: Md. Rezwanul Haque
'''
n, m = map(int,input().split())
ans = 1
t = [input()for i in range(n)]

for i in zip(*t):
    ans*=len(set(i))%1000000007
print(ans)