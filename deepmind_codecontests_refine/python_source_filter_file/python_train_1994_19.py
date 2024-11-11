n=int(input())
l=list(map(int,input().rstrip().split()))
s=list(set(l))
if len(s)>3:
    print(-1)
elif len(s)==1:
    print(l[0])
elif len(s)==2:
    if abs(s[0]-s[1])%2==0:
        print(abs(s[0]-s[1])//2)
    else:
        print(abs(s[0]-s[1]))
else:
    s.sort()
    if s[1]-s[0]==s[2]-s[1]:
        print(s[1]-s[0])
    else:
        print(-1)