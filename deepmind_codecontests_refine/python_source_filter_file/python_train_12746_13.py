s = input().strip()
a = [0]*26
for i in range(len(s)):
    a[ord(s[i]) - ord('A')] += 1
if sum(a) - a[0] - a[7] - a[8] - a[12] - a[14] - a[15] - a[19] - a[20] - a[21] - a[22] - a[23] == 0 and s == ''.join(reversed(list(s))):
    print("YES")
else:
    print("NO")