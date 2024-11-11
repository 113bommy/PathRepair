from collections import Counter
n,k=list(map(int,input().split()))
s=input()
s1=Counter(s)
a,c=0,0
d={}
for i in s:
    if i in d:
        d[i]+=1
    else:
        d[i]=1
        c+=1
    a=max(a,c)
    #print(c)
    if d[i]==s1[i]:
        c-=1
    print(c)
print('YES' if a>k else 'NO')