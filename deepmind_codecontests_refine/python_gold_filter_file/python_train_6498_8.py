s=input()
l=len(s)
an=0
ans=[0]*(l+1)
prev=-1
for i in range(0,l):
    if 'bear' in s[i:i+4]:
        ans[i]=1
        an+=((i-prev)*(l-i-3))
        prev=i
print(an)        

