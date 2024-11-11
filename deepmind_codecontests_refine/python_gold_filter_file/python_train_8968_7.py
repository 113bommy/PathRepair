s = input()
i = 0
count = [0, 0, 0]
ans = 0
while i < len(s):
    j = i
    while j + 1 < len(s) and s[j + 1] == s[i]:
        j += 1
    size = j - i + 1
    if s[i] == 'v':
        num = size - 1
        count[2] += num * count[1]
        count[0] += num
    else:
        count[1] += count[0] * size
    #print(count)
    i = j + 1
print(count[2])