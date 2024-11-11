from collections import Counter

A = input()
AC = Counter(A)

B = input()
BC = Counter(B)

letters = [chr(ord('a') + i) for i in range(ord('z') - ord('a') + 1)]

result = 0

a, b, c = 0, len(A), 0

#for k in range(len(A) - len(B) + 1):
#    needed = 0
#    for x in letters:
#        needed += max([0, k * BC[x] - AC[x]])
#
#    if needed <= AC['?']:
#        result = k
#    else:
#        break

while a < b:
    c = (a + b) // 2

    needed = 0
    for x in letters:
        needed += max([0, c * BC[x] - AC[x]])

    if needed <= AC['?']:
        a = c + 1
    else:
        b = c

result = a - 1

C = list(A)

i = 0
for x in letters:
    cneed = max([0, result * BC[x] - AC[x]])
    while cneed > 0:
        if C[i] == '?':
            C[i] = x
            cneed -= 1
        i += 1

while i < len(A):
    if C[i] == '?':
        C[i] = 'z'
    i += 1

print(''.join(C))
