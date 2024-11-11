n=int(input())
s=input()
one=0
zero=0
d={}
ans=0
d[0]=-1
for i in range(len(s)):
    if s[i]=='1':
        one+=1
    else:
        zero+=1
    k=one-zero
    if k not in d:
        d[k]=i
    else:
        ans=max(ans, i-d[k])
print(ans)