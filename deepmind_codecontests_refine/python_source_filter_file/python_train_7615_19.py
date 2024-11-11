t=int(input())
for _ in range(t):
    c=0
    n,k= (int(x) for x in input().split())
    while n!=0:
        if n%k==0:
            n=n/k
            c+=1
        else:
            c +=(n%k)
            n -=(n%k)
    print(int(c))
