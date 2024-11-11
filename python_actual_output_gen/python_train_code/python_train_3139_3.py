a,b,c,d = map(int, input().split())
left = max(a,c)
right = min(b,d)
print(right-left)