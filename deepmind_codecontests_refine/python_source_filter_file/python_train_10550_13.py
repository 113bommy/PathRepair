d1={}
for i in range(1,int((10**9)**0.5)+1):
    d1[(i*(i+1)//2)]=1
n=int(input())
import sys
for k in d1:
    if (n-k) in d1:
        print("YES")
        sys.exit()
print("NO")