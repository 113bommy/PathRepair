t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    if n<k:
        print(k-n)
    elif n==k:
        print(0)
    else:
        print(0)