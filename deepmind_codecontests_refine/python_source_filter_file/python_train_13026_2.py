from collections import Counter

get=lambda:list(map(int,input().split()))

n,k=get()
l=get()

s=Counter(l)

if min(s.values())<k and n>k:
    print("YES")
    e=0
    for i in s:
        e+=s[i]
        s[i]=e
    ans=[]
    for i in l:
        ans.append(str(s[i]%k+1))
        s[i]-=1
    print(' '.join(ans))
        
else:
    print("NO")
