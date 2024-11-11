import sys

input()
s = input()
maxc = len(s) // 2 * 9
for i in range(1, maxc):
    sum = 0
    r = "Y"
    l = 0
    for c in range(len(s)):
        sum += int(s[c])
        if sum == i:
            sum = 0
            l += 1
        elif sum > i:
            r = "N"
            break
    if r == "Y" and sum == 0 and l > 1:
        print("YES")
        sys.exit()

print("NO")