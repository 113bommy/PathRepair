import sys,math 
s=input()
n=len(s)
a=[[0] for i in range(26)]
for i in range(n):
    a[ord(s[i])-97].append(i+1)
for i in range(26):
    a[i].append(n)
ans=n+1    
for i in range(26):
    cur=0
    for j in range(1,len(a[i])):
        cur=max(cur,a[i][j]-a[i][j-1])
    ans=min(ans,cur)
print(ans)    