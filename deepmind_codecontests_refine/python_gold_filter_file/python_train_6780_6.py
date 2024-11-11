m = input()
k = int(input())
l = 0
s = False
for i in range(len(m)):
    if m[i] == '?':
        l += 1
    elif m[i] == '*':
        l += 1
        s = True
if k < len(m) - l:
    if len(m) - k <= 2 * l:
        j = 1
        while len(m) - l > k:
            if m[j] == '?' or m[j] == '*':
                m = m[:j - 1] + m[j:]
            else:
                j += 1
    else:
        print("Impossible")
        exit(0)
elif k > len(m) - l:
    if s:
        j = m.find('*')
        while len(m) - l < k:
            m = m[:j] + m[j - 1] + m[j:]
            j += 1
    else:
        print("Impossible")
        exit(0)
for i in range(len(m)):
    while m[i] == '?' or m[i] == '*':
        m = m[:i] + m[i + 1:]
    if i >= k - 1:
        break
while m[len(m) - 1] == '?' or m[len(m) - 1] == '*':
    m = m[:-1]
print(m)