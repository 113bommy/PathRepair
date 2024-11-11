#Ashish Sagar
import sys
import math
n=int(sys.stdin.readline())
s=list(sys.stdin.readline())
s.pop()
ans=""
for i in range(n):
    if len(ans)%2==0:
        ans+=s[i]
    else:
        if s[i]!=ans[-1]:
            ans+=s[i]
if len(ans)%2!=0:
    a=ans[1:]
    print(len(s)-len(a))
    print(a)
else:
    print(len(s)-len(ans))
    print(ans)
            
 
    