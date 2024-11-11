n, s = map(int,input().split())
if s>=2*n:
    print("YES")
    for i in range(n-1):
        print(2,end = " ")
        s-=2
    print(s)
    print(2)
else:
    print("NO")





