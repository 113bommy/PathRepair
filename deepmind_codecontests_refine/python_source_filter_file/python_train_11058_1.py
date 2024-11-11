for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    if n%2==0:
        A=a[0:n-1]
        B=a[n-1:]
        print(B[0]-A[-1])
    else:
        A=a[0:n]
        B=a[n:]
        print(B[0]-A[-1])