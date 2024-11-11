p=[1]*1001
for i in range(2,1001):
    if p[i]:
        for j in range(i,1001,i):p[j]=0
        p[i]=1
a=input()
z=len(a)
l=[0]*26
for i in a:l[ord(i)-97]+=1
gh=0
for i in range(z//2+1,z+1):gh+=p[i]
if max(l)<z-1-gh:exit(print("NO"))
ans=['']*(z+1)
t=l.index(max(l))
for i in range(2,1+(z//2)):ans[i]=chr(t+97);l[t]-=1
for i in range(2+(z//2),z):
    if p[i]:ans[i]=chr(t+97);l[t]-=1
j=0
for i in range(1,z+1):
    if ans[i]=='':
        while l[j]<=0:j+=1
        ans[i]=chr(j+97);l[j]-=1
print("YES")
print(''.join(ans[1::]))