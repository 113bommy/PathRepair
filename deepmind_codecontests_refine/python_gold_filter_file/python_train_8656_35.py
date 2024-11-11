res = []
n = int(input())
for i in range(n):
    k = int(input())
    num = input()
    firstIndex = num.find('8')
    res.append("YES" if k - firstIndex >= 11 and firstIndex > -1 else "NO")
print(*res, sep="\n")