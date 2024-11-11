import sys
def input():
    return sys.stdin.readline().strip()

k = int(input())
s = [''] + list(reversed(list(input())))
print(s)
out = [1] * 2**(k+1)

def update(i):
    if s[i] == '1':
        out[i] = out[i*2]
    elif s[i] == '0':
        out[i] = out[i*2+1]
    else:
        out[i] = out[i*2] + out[i*2+1]

for i in range(2**k-1, 0, -1):
    update(i)

ans = []
q = int(input())
for _ in range(q):
    i, c = input().split()
    i = 2**k - int(i)
    if c == s[i]:
        ans.append(out[1])
    else:
        s[i] = c
        update(i)
        while i > 1 and (s[i//2] == '?' or (i & 1) ^ int(s[i//2])):
            i //= 2
            update(i)
        ans.append(out[1])

print('\n'.join(map(str, ans)))