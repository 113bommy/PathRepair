x, y, z = map(int,input().split())
print(min(y,z), max(0,y+z-x))