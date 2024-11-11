s = input()
s1 = input()

if len(s) < len(s1):
    s1, s = s, s1

q = 499
p = int(1e11 + 7)

n = len(s)
hs = [0] * (n + 1)
pw = [1] * (n + 1)

for i in range(n):
    hs[i + 1] = (hs[i] * q + ord(s[i])) % p
    pw[i+1] = (pw[i] * q) % p

def get_hash(a, b): #hash [a, b)
    return (hs[b] - (hs[a] * pw[b-a]) % p + p) % p

h1 = 0
ans = 0
for x in range(len(s1)):
    h1 = (h1 * q + ord(s1[x])) % p
    if not len(s1) % (x + 1):
        fl = True
        for i in range(0, len(s), x + 1):
            if get_hash(i, min(i + x + 1, len(s))) != h1:
                fl = False
                break
        if fl:
            ans += 1
print(ans)



