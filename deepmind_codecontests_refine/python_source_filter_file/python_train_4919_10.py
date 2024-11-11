n, s = map(int,input().split())
if s>=2*n:
    print("YES")
    for i in range(n):
        print(s,end = " ")
        s-=2
    print()
    print(2)
else:
    print("NO")





