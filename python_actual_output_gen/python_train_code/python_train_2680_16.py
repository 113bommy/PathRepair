t = [input().strip() for i in range(3)]
r = t[2][::-1] + t[1] + t[0][::-1]
print("YES" if "".join(t) == r else "NO")
