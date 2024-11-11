l, r, d = map(int, input().split())

s1 = (l-1) // d
s2 = r // d

print(s2-s1)
