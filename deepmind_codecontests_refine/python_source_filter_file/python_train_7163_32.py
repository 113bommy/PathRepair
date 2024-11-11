x, y, z = map(int,input().split())
print(min(y,z), max(0, x-y-z))