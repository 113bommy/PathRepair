n = str(input())
x,y,z = 0,0,0
x += n.count("144")
y += n.count("14")
z += n.count("1")
print("YES" if len(n) == 3*x+2*y+z-x-y else "NO")