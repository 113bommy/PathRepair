n=int(input())
s=input()
k=s.count('><')
if k==0:
    pass
elif k==1:
    k=s.find('><')
    for i in range(k+1,n):
        if s[i]=='<':
            n-=1
        else:
            break
    for i in range(k,-1,-1):
        if s[i]=='>':
            n-=1
        else:
            break
else:
    k=s.rfind('><')
    for i in range(k+1,n):
        if s[i]=='<':
            n-=1
        else:
            break
    q=s.find('><')
    for i in range(k,-1,-1):
        if s[i]=='<':
            n-=1
        else:
            break
    n-=k-q+1
print(n)
