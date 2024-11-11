n,m = list(map(int,input().split()))
a = list(map(int,input().split()))
b = list(map(int,input().split()))
for target in range(2**9+1):
    f = 0
    for i in a:
        fg = 0
        for j in b:
            
            if (i&j)&target==target:
                fg = 1
                continue
        if fg==0:
            break
        else:
            f+=1
    if f==n:
        print(target)
        break