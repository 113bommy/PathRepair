

import sys
import math

#sys.stdin = open("F:\PY\\test.txt", "r")
input = lambda: sys.stdin.readline().rstrip("\r\n")


n = int(input())
ar = list(map(int, input().split()))

if n==1:
    print(1, 1)
    print(ar[0])
    print(1, 1)
    print(1)
    print(1, 1)
    print(-1)
    sys.exit(0)

arMod = [0]*n
print(1, n)
for i in range(n):
    ans = 0
    mult=abs(ar[i])//n+(1 if ar[i]%n!=0 else 0)
    temp2 = abs(ar[i])-(mult*(n))
    mult2 = (n-1)-abs(temp2)
    if mult2 ==0:
        mult2=n-1
    mult+=mult2   
    #print(temp2, mult2, mult) 
    if ar[i]>=0:
        print(-mult*n, end=" ")
        arMod[i]=ar[i]-(mult*n)
    else:
        arMod[i]=ar[i]+(mult*n)
        print(mult*n, end=" ")
       
        
     
print()
print(1, n-1)
print(arMod[0]*(-1), end=" ")
for i in range(1, n-1):
    print(arMod[i]*(-1), end=" ")
    arMod[i]=0
#sys.exit(0)     
      
print()   
print(2, n)

for i in range(1, n-1):
    print(arMod[i]*(-1), end=" ")

print(arMod[n-1]*(-1))
