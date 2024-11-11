def array_of(f, *dim):
    return [array_of(f, *dim[1:]) for _ in range(dim[0])] if dim else f()

def atoi(c):
    return ord(c) - ord('a')

def itoa(i):
    return chr(i + ord('a'))

n = int(input())
s, t = input(), input()

s = list(map(atoi, reversed(s)))
t = list(map(atoi, reversed(t)))

ss = array_of(int, n+1)
for i in range(n):
    x = s[i] + t[i]
    if x > 26:
        ss[i] += x-26
        ss[i+1] += 1
    else:
        ss[i] += x

for i in range(n+1-1, -1, -1):
    if ss[i]%2 == 1:
        ss[i-1] += 26
    ss[i] //= 2

out = []
for i in range(n-1, -1, -1):
    out.append(itoa(ss[i]))
print(''.join(out))