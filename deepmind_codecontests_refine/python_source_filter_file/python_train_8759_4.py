n = int(input())
s = input()
m = 5000
for i in range(n - 3):
    c = 0
    z = 0
    for j in range(i, i + 4):
        if c == 0:
            z += (min(abs(ord(s[j]) - ord('A')), (abs(ord('Z') - ord(s[j])) + 1)))
        elif c == 1:
            z += (min(abs(ord(s[j]) - ord('C')), (abs(ord('Z') - ord(s[j])) + 3)))
        elif c == 2:
            z += (min(abs(ord(s[j]) - ord('T')), (abs(ord('Z') - ord(s[j])) + 20)))
        else:
            z += (min(abs(ord(s[j]) - ord('G')), (abs(ord('Z') - ord(s[j])) + 7)))
        c += 1
        if c == 4:
            m = min(m, z)
print(m)
