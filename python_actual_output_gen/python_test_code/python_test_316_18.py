s = list(input())
ans = 0
gl = ['a', 'e', 'i', 'o', 'u']
nums = ['0', '2', '4', '6', '8']
i = 0
while i < len(s):
    if (s[i] in gl or s[i] in nums):
        ans += 1
    i += 1
print(ans)