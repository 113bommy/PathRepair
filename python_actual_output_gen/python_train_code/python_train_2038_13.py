n, k, c = map(int, input().split())
s = input()
dpl = []
dpr = []
ans = []
count = 0
i = 0
while count < k:
    if s[i]=="o":
        dpl.append(i)
        count += 1
        i += c+1
    else: i += 1
count = 0
i = n-1
while count < k:
    if s[i]=="o":
        dpr.append(i)
        count += 1
        i += -c-1
    else: i -= 1
dpr.sort()
for i in range(len(dpl)):
    if dpl[i] == dpr[i]: ans.append(i+1)
print(*ans, sep="\n")