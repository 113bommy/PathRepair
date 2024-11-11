t, s, x = map(int, input().split())
if x == t:
    print("YES")
elif 0 < x - t < s:
    print("NO")
elif x > t and ((x - t) % s == 0 or (x - t - 1) % s == 0):
    print("YES")
else:
    print("NO")
