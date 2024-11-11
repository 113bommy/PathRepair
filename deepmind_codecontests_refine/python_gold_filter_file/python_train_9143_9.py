a,b,c,d = map(int, input().split())
left = max(a,c)
right = min(b,d)
print(max(0,right-left))