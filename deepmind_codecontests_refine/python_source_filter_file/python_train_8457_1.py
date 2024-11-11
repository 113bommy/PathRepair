t= int(input())

for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))

    if b.count(1)!=0 and b.count(1)!=0:
        print('Yes')
    else:
        c= -1
        for i in range(1,n):
            if a[i-1]>a[i]:
                print('No')
                break
        else:
            print('Yes')