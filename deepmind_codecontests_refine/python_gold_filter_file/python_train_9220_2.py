n = int(input())
s = input()
d = dict()
for i in range(n):
    s1 = input()
    s2 = s1[0:3]
    s3 = s1[5:]
    if s2 in d:
        d[s2] += 1
    else:
        d[s2] = 1
    if s3 in d:
        d[s3] += 1
    else:
        d[s3] = 1
flag = False
for i in d:
    if d[i] % 2 != 0 and i != s:
        print('contest')
        flag = True
        break
if not flag:
    print('home')