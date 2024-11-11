n, t = map(int, input().split())

t-=1

portals = [int(i) for i in input().split()]

i = 0

while i < t:
    i += portals[i]

print("YES" if i == t else "NO")
