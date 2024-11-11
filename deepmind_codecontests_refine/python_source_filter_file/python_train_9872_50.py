a, b = map(int, input().split(" "))
b = b + int(b/100)
print(a*(100**b))