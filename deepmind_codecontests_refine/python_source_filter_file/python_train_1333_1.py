a = [int(input()) for _ in range(5)]
b = 10-min([a[i]%10 for i in range(5) if 0 < a[i]%10] or 10)
print(sum([(-(-a[i]//10)) for i in range(5)])*10-b)