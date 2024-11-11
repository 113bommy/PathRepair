a, b = input().split()
a, b_100 = int(a), int(b.replace('.', ''))
print(a * b // 100)
