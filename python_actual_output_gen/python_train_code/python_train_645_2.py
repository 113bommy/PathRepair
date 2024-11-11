s = input().strip()

diffs = 0
for i in range(len(s) // 2):
    if s[i] != s[len(s) - i - 1]:
        diffs += 1

if diffs == 0 or len(s) % 2 == 1 and diffs == 1:
    print("YES")
else:
    print("NO")
