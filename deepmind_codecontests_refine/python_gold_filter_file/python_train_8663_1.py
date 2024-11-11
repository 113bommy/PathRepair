s = input()

arr1 = [0] * 26
arr2 = [[0] * 26 for i in range(26)]

for i in range(len(s)):
    c = ord(s[i]) - ord('a')
    for j in range(26):
        arr2[j][c] += arr1[j]
    arr1[c] += 1

    # print(arr1)
    # print(*arr2, sep='\n')
    # print()

ans = 0

for i in range(26):
    ans = max(ans, arr1[i])
for i in range(26):
    for j in range(26):
        ans = max(ans, arr2[i][j])

print(ans)
