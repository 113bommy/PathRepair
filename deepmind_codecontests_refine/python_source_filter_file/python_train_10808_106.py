a,b,c,d = map(int, input().split())
print("Yes" if abs(a-b)<=3 or abs(b-c)<=3 or abs(c-a) <=3 else "No")