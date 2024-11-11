n, s = map(int,input().split())
if n*2 >= s:
    print("NO")
else:
    print("YES")
    print("2 "*(n-1)+str(s-2*n+2))
    print(1)
