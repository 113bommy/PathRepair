q=int(input())
for i in range(q):
    n,a,b=map(int,input().split())
    if a*2<b:
        print(n*a)
    else:
        if n%2==0:
            print(int(n/2*b))
        else:
                print(int(n//2*b)+a)