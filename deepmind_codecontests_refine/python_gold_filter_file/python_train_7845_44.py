# fancy fence
n=int(input())
for i in range(n):
    s=0
    m=int(input())
    for j in range(358):
        if m*(j+3)/(j+1)==180:
            s=1
            break
    print('YES' if s==1 else 'NO')