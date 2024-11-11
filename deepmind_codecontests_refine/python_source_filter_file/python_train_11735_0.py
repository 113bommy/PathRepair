from bisect import *
n,k=map(int,input().split())
s=input()
from collections import *
al=defaultdict(int)
for i in range(len(s)):
    al[s[i]]+=1
ans=[0 for i in range(26)]
for i in range(26):
    ans[i]=al[chr(97+i)]
for i in range(26):
    ans[i]+=ans[i-1]
m=bisect_left(ans,k)
if(m>0):
    
    lets=k-ans[m-1]
else:
    lets=k
temp=[]
count=0

for i in range(len(s)):
    if(ord(s[i])-97>m):
        temp.append(s[i])
    elif(ord(s[i])-97==m):
        if(count<lets):
            count+=1
        else:
            temp.append(s[i])
print(''.join(map(str,temp)))
            
