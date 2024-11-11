n = int(input())
s = [input() for _ in range(n)]
for i, r in enumerate(s):
    if "oo" in r:
        s[i] = r.replace("oo", "++", 1)
        print("YES")
        print("\t".join(s))
        break
else:
    print("NO")