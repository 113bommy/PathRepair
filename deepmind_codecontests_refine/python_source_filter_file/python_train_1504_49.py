n=int(input())
l=-10**9
r=10**9
for i in range(n):
    s=input().split()
    s[1]=int(s[1])
    if s[2]=='Y':
        if s[0]=='>=':
            l=max(l,s[1])
        elif s[0]=='>':
            l=max(l,s[1]+1)
        elif s[0]=='<=':
            r=min(r,s[1])
        else:
            r=min(r,s[1]-1)
    else:
        if s[0]=='>=':
            r=min(r,s[1]-1)
        elif s[0]=='>':
            r=min(r,s[1])
        elif s[0]=='<=':
            l=max(l,s[1]+1)
        else:
            l=max(l,s[1])
if l>r:
    print('Impossible')
else:
    print(l)