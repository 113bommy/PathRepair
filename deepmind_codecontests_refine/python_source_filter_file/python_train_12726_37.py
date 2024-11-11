t=int(input())
for ts in range(t):
    n,m=map(int, input().split(" "))
    if n==1:
        print(0)
    elif n==2:
        print(m)
    elif n>2:
        print(2*n)