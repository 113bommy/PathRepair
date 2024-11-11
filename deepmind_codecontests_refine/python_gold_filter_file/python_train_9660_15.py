s=input()
l=len(s)
a=[0 for i in range(l+1)]
for i in range(l):
    if s[i]=='<':
        a[i+1]=max(a[i+1],a[i]+1)
        #print(a)
for i in range(l-1,-1,-1):
    if s[i]=='>':
        a[i]=max(a[i+1]+1,a[i])
        #print(a)
print(sum(a))