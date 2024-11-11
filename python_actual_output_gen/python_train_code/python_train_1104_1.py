'''
Created on May 18, 2016

@author: Md. Rezwanul Haque
'''
n = int(input())
A = list(map(int,input().split()))
A.sort()

ans = []
for i in range (n):
    rez = i//2;
    if i%2 == 0:
        z = A[rez]
    else:
        z = A[n-1-z]
    ans.append(z)
print(' '.join(map(str,ans)))
