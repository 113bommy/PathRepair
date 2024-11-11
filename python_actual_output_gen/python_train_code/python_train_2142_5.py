s1,s2=input().split()
n=len(s1)
h=s1[0]
ans=h
for i in range(1,n):
    if h>s1[i]:
        ans+=s1[i]
    else:
        break
ans+=s2[0]
print(ans)
