s = list(map(int, input().split()))
lis = [s[0]]
for i in range(1,4):
    if s[i]<s[i-1]:lis.append(s[i])
cnt = 0
for i in range(s[4], min(lis)):
    m = i
    for j in lis:
        m = m%j
    if m == i: cnt += 1
print(cnt)