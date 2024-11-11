t=int(input())
for i in range(t):
    n=int(input())
    m=0
    if n%2==0:
        m=n/2-1
    else:
        m=(n-1)/2
    print(m)