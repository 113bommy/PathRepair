letters = list(input())
l = len(letters)
k = int(input())
w = [int(x) for x in input().split()]
res = 0
maxW = max(w)
for i in range (l):
    res += (i + 1) * w[ord(letters[i]) - ord('a')]
for i in range (k):
    res += (k + i + 1) * maxW
print(res)