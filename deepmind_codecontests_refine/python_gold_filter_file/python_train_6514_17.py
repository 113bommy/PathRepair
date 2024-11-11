a, b = map(int, input().split())
if a==b and a!=0:
    print("YES")
elif a+1==b:
    print("YES")
elif b+1==a:
    print("YES")
else:
    print("NO")