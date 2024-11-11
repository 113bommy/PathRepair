a,b = input().split()
t = int(a+b)
print("Yes" if t == int(t**0.5)**2 else "No")
