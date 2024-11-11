w,a,b = map(int, input().split())

print(max(0,min(a-b-w,b-a-w)))