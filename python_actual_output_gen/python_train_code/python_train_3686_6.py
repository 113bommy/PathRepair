t=int(input())
for i in range(t):
    r,g,b=list(map(int,input().split()))
    o=max(r,g,b)
    if o>((r+g+b)-o):
        print('No')
    else:
        print('Yes')

