a, b, c, d = map(int, input().split())
e = a + b - (c + d)
print("Left" if e>0 else "Blanced" if e==0 else "Right")