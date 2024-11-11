from sys import stdin, stdout
import string
input = stdin.readline

n, t = list(map(int, input().split()))
a = input().strip()
b = input().strip()

def not_a_not_b(a,b):
    letters = string.ascii_lowercase
    for el in letters:
        if el != a and el != b:
            return el

diver = []
equal = []
ans = list(a)

for index,el in enumerate(a):
    if el == b[index]:
        equal.append(index)
    else:
        diver.append(index)

if len(diver) > t * 2:
    stdout.write("-1")
else:
    if t >= len(diver):
        for ind in diver:
            ans[ind] = not_a_not_b(a[ind], b[ind])
        t -= len(diver)
        for ind in range(t):
            ans[equal[ind]] = not_a_not_b(a[equal[ind]],b[equal[ind]])
    else:
       s = len(diver)
       s -= t
       for ind in diver[:s]:
          ans[ind] = a[ind]
       for ind in diver[s:s+s]:
          ans[ind] = b[ind]
       for ind in diver[s+s:]:
          ans[ind] = not_a_not_b(a[ind], b[ind])

stdout.write("{}\n".format("".join(ans)))

