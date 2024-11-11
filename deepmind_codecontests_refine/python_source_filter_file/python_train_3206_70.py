a,b,c = map(int, input().split())
print(max(a - c, 0), b + min(a - c, 0))