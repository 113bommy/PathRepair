t=int(input())
for t in range(t):
    n,k=map(int,input().split())
    if k>n:
        print(k-n)
    elif n%2==0 and k%2==0:
        print(0)
    else:
        print(1)