n,k=map(int,input().split())
s,s1=input(),''
c=1
min=99999
d=set(s)
if len(d)==1:
    print(s+s[0]*(k-1))
    exit()
while (c<(n+1)/2):
    if s[:c]==s[len(s)-c:]:
        if min>len(s[:c]+s[c:]*k):
            min=len(s[:c]+s[c:]*k)
            s1=(s[:c]+s[c:]*k)
    c+=1
if s1!='':
    print(s1)
else:
    print(s*k)