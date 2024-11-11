import sys
input = sys.stdin.readline
out = sys.stdout
k, n = map(int,input().split())
s = input()
if k == n == 1:
    print('')
else:
    d = {chr(i + 97):0 for i in range(27)}
    for i in range(k):
        d[s[i]] += 1
    cur = ''
    for k in d.keys():
        if n >= d[k]:
            n -= d[k]
        else:
            cur = k
            break
    for i in s:
        if i < cur:
            continue
        elif i == cur:
            if n == 0:
                out.write(i)
            else:
                n -= 1
        else:
           out.write(i)