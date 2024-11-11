II = lambda: int(input())
n,a,b,c = (II() for _ in range(4))
if a <= (b-c):
    glass = 0
    plastic = n // a
else:
    glass = (n-b) // (b-c) + 1
    rem = glass * (b-c)
    plastic = (n - rem) // a
print(max(glass + plastic, 0))
