a = input()
b = input()
c = input()
d = a + b
d_count = [0] * 26
c_count = [0] * 26
for i in d:
    d_count[ord(i) - 65] += 1

for i in c:
    c_count[ord(i) - 65] += 1

for i in range(26):
    if c_count[i] < d_count[i]:
        print('NO')
        break
else:
    print('YES')