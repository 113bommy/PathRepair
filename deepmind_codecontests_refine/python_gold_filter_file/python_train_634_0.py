s=input()
m=10**9+7
l=list()
count=0
for c in s:
    if c=='a':
        count+=1
    if c=='b' and count>0:
        l.append(count)
        count=0
if count>0:
    l.append(count)
ans=1
for i in l:
    ans=(ans*(i+1))%m
print(ans-1)