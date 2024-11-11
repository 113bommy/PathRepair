socks = input().split(' ')
k = 0
a, b = int(socks[0]), int(socks[1])
d = (max(a, b) - min(a, b)) // 2
print(min(a, b), d)
