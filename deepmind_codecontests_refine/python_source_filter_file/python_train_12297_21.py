q = int(input())
for _ in ' '*q:
    l, r =map(int, input().split())
    if l%2==0 and r%2==0:
        print((l-r)/2+r)
    elif l%2==0 and r%2!=0:
        print(-((r-l)//2+1))
    elif l%2!=0 and r%2==0:
        print((r-l)//2+1)
    elif l%2!=0 and r%2!=0:
        print((l-r)/2-r)