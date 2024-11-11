N = int(input())

a_end = 0
b_start = 0
ab = 0
zz = 0
for n in range(N):
    s = input()
    ab = ab + s.count('AB')
    if s[-1] == 'A':
        a_end = a_end + 1
    if s[0] == 'B':
        b_start = b_start + 1
    if s[-1] != 'A' and s[0] != 'B':
        zz = zz + 1

print(ab + min(a_end, b_start, N - 1 - zz))
