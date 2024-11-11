a, b = map(int, input().split(" "))
b += int(b/100)
print(b*(100**a))