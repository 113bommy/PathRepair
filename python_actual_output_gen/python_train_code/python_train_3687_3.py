t=int(input())
for _ in range(t):
    n,a,b,c,d=map(int,input().split(' '))
    w1=a-b
    w2=a+b
    mw1=c-d
    mw2=c+d
    if(n*w2<mw2 or mw1<n*w1):
        print('No')

    else:
        print('Yes')
