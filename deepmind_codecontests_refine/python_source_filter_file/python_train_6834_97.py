n=int(input())
if n%2==0:
    a="8"*(n//2)
else:
    a="8"*(n//2)+"4"
if len(a)>=18:
    print(-1)
else:
    print(a)