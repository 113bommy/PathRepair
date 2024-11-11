y, b, r = map(int, input().split())

'''
bl <= [n / 3] 
a = bl + 1 <= r || bl <= r - 1
c = bl - 1 <= b || bl <= b + 1
'''

blue = min(r - 1, (y + b + r) // 3, b)

print(blue * 3)