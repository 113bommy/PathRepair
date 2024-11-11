import math
import time
from collections import defaultdict,deque
from sys import stdin,stdout
from bisect import bisect_left,bisect_right
MOD=1000000007
s=input()
n=len(s)
dp=[[1,0] for _ in range(n+2)]
for i in range(2,n+1):
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD
    dp[i][1]=(dp[i-1][0])%MOD
ans=1
i=1
temp=1
while i<n:
    if(s[i]=="m" or s[i]=="w"):
        ans=0
    if(s[i]=="u" and s[i-1]=="u"):
        temp+=1
    elif(s[i]=="n" and s[i-1]=="n"):
        temp+=1
    else:
        ans*=(dp[temp][0]+dp[temp][1])%MOD
        temp=1
    i+=1
ans*=(dp[temp][0]+dp[temp][1])%MOD
if(s[0]=="m" or s[0]=="w"):
    ans*=0
print(ans)
