s1 = input()
s2 = input()
s3 = input()
a =[]
b = []
c = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

s = s1 + s2
e = True
for i in range(26):
    if s.count(c[i]) < s3.count(c[i]):
        e = False
if e and len(s) < len(s3):
    print('YES')
else:
    print('NO')