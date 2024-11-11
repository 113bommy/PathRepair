# fancy fence
n=int(input())
for i in range(n):
    s=0
    m=int(input())
    for j in range(357):
        if m*(j+3)/(j+1)==180:
            i=1
            break
    print('YES' if i==1 else 'NO')