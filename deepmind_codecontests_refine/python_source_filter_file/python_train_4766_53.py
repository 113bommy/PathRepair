x,y = map(int, input().split())
i = 'yes' if x * 2 <= y <= x * 4 and y % 2 == 0 else 'no'
print(i)