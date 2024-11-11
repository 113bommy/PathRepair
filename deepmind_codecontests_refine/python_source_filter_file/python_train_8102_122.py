x,y,z = map(int, input().split())
x = x-2*z
ans = x // (y+z)
print(ans)