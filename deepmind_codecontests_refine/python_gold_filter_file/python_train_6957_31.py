
a,b = input().split()
ab = int(a+b)

print("Yes" if ab%(ab**0.5)==0 else "No")
