s = input().strip()
letters = [0] * 30
for i in range(len(s)):
    letters[ord(s[i]) - ord('a')] += 1
ans = min(letters[ord('i') - ord('a')], letters[ord('e') - ord('a')] // 3)
ans = min(ans, letters[ord('t') - ord('a')])
ans = min(ans, (letters[ord('n') - ord('a')] - 3) // 2 + 1)
print(max(0, ans))