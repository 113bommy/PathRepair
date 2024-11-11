n = int(input())
s = list(input())
ans=0
tem=[]
for i in range(n):
    if s[i]>='A' and s[i]<='Z':
        ans=max(ans,len(set(tem)))
        tem=[]
    else:
        tem+=[s[i]]
print(ans)            