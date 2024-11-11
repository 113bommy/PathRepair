for _ in range(int(input())):
    n,k1,k2=map(int,input().split())
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    ans="YES" if sum(a)>sum(b)  else "NO"
    print(ans)
