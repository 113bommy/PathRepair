#codeforces_1009D
from math import *
n,m = [int(e) for e in input().split(" ")]
if m<n:
    print("Impossible")
    exit();
ans = []
len = 0
for k in range(1,n+1):
    for j in range(k+1,n+1):
        if gcd(j,k)==1:
            len += 1
            ans.append(str(k)+" "+str(j))
            if len == m:
                print("Possible")
                print("\n".join(ans))
                exit();
print("Impossible")