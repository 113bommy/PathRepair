s1 = input()
s2 = input()
s3 = input()
combined = s1 + s2
ans = True
for i in combined:
    if combined.count(i) != s3.count(i):
        ans = False
        break
print("YES" if ans else "NO")
