
a, b, c, d = map(int, input().split())
print("Yes" if abs(c-a) <= d and abs(b-a) <= d and abs(c-b) <= d else "No") 
