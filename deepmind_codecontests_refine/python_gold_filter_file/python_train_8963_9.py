n = int(input())
n-=1
R=0
L=0
m={ input().split()[1]:0}
while n:
    a,b = input().split()
    if a=='L':
        L-=1
        m[b]=L
    elif a=='R':
        R+=1
        m[b]=R
    else:
        print(min(R-m[b],m[b]-L))
    n-=1