# You lost the game.
a,b,s = map(int, input().split())
d = abs(b)+abs(a)
if d < s or (s-d) % 2:
    print("No")
else:
    print("Yes")
