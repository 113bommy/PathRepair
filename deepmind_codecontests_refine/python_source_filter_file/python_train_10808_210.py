a,b,c,d = map(int, input().split())
print("Yes" if abs(a-b)<=d or abs(b-c)<=d or abs(c-a) <=d else "No")