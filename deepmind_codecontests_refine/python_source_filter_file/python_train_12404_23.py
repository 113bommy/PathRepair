n, m, r = map(int, input().split())
b = min(map(int, input().split())) 
print(r //  b * max(map(int, input().split())) + r % b)
