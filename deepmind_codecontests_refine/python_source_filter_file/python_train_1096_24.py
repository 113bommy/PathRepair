n = int(input())
a = list(map(int, input().split()))
if n == 2:
    print(1)
else:
    maxa =0
    mina = 101
    maxap=0
    minap = 0
    for i in range(n):
        if a[i] < mina:
            mina = a[i]
            minap = i
        if a[i] > maxa:
            maxa=a[i]
            maxap=i
    if(abs(minap-maxap) == n-1):
        print(minap-maxap)
    else:
        print(max([minap,maxap,abs(n-1-maxap),abs(n-1-minap) ]))