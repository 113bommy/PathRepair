'''
Created on Apr 29, 2016
Gmail : r.haque.249.rh@gmail.com
@author: Md. Rezwanul Haque
'''
mod = 10**9 + 7
n,k = map(int,input().split())#6 2

a = list(map(int,input().split()))#38 56 49
b = list(map(int,input().split()))#7 3 4

ans = 1

for i in range(n//k):
    cnt = (10**k-1)//a[i] - (10**(k-1)*(b[i]+1) - 1)//a[i]
    #print("C1= ",cnt)
    if b[i]!=0:
        cnt += (10**(k-1)*b[i]-1)//a[i]+1
        #print("C2= ",cnt)
    ans *= cnt%mod
print(ans)