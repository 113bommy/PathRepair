c=list(map(int,input().split()))
s=sum(c)
if s%len(c)==0:
    print(s//len(c))
else:
    print("-1")