a, b, c, d = map(int, input().split())
e = a + b - (c + d)
print("Left" if e>0 else "Balanced" if e==0 else "Right")
