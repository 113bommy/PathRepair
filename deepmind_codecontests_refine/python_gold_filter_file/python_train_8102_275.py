x,y,z = map(int,input().split())
yz = y + z
x -= z
print(x // yz)