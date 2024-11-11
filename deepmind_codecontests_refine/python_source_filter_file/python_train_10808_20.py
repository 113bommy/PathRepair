a,b,c,d = map(int,input().split())
print("Yes" if abs(a - b) <= d and abs(c - c) <= d or abs(a - c) <= d else "No")
