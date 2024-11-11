a, b = input().split()
ab = int(a+b)

print("Yes" if ab**(1/2)%1==0 else "No")