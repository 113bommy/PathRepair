t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    if n==k:
        print(0)
    elif k==0:
        if n%2==0:
            print(0)
        else:
            print(1)
    elif n==0:
        print(k)
    elif k>n:
        print(min(k-n,n))
    else:
        if k%2!=0 and n%2!=0:
            print(0)
        elif n%2==0 and k%2==0:
            print(0)
        else:
            print(1)