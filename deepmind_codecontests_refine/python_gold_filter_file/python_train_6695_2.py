from sys import stdin, stdout

def count(s):
    return sum(1 for c in s if c == '1')

def build(s1, s2, m):
    i1 = 0
    i2 = 0
    answer = ''
    while i1 < len(s1) and i2 < len(s2):
        if s1[i1] == s2[i2]:
            answer += s1[i1]
            i1 += 1
            i2 += 1
        elif s1[i1] != m:
            answer += s1[i1]
            i1 += 1

        else:
            answer += s2[i2]
            i2 += 1

    return answer + s1[i1:] + s2[i2:] + '\n'

n = int(stdin.readline())
for _ in range(n):
    k = int(stdin.readline())
    a = stdin.readline().strip()
    b = stdin.readline().strip()
    c = stdin.readline().strip()
    arr0 = []
    arr1 = []
    for s in [a, b, c]:
        if count(s) >= k:
            arr1.append(s)
        else:
            arr0.append(s)
    if len(arr0) > 1:
        stdout.write(build(arr0[0], arr0[1], '0'))
    else:
        stdout.write(build(arr1[0], arr1[1], '1'))
