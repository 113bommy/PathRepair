s = input()
k = int(input())
l = list(map(int, input().split()))
sum = 0
for i in range(len(s)):
    for j in range(len(l)):
        x = chr(97 + j)
        if (x == s[i]):
            sum += (i+1) * l[j]
print(sum)
l.sort(reverse=True)
for a in range(k):
    sum += l[0] * (a + len(s) + 1)
print(sum)
