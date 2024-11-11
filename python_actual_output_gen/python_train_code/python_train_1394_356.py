a,b,x = map(int,input().split())
print("Yes" if a <= x and x < a+b-1 else "No")