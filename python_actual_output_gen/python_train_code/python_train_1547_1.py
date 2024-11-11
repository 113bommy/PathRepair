r,g,b = input().split()
r = int(r)
g = int(g)
b = int(b)

div_r = (r+1)/2
div_g = (g+1)/2
div_b = (b+1)/2
ans = max(3*div_r + 27, 3*div_g + 28, 3*div_b + 29)
print(int(ans))
