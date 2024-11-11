from sys import stdin, stdout
def fin(): return stdin.readline()
def fout(x): stdout.write(str(x) + '\n')

n, arr, ans = int(fin()), list(map(int, fin().split())), 0

for i in arr: ans ^= i

pre_xor, post_xor, now = [0 for i in range(n+1)], [0 for i in range(n+1)], 0

for i in range(0, n+1):
    now ^= i
    pre_xor[i] = now

now = 0
for i in range(n, -1, -1):
    now ^= i
    post_xor[i] = now


# print(pre_xor, post_xor, sep='\n')
for i in range(1, n+1):
    if (n//i) % 2 == 0: ans ^= pre_xor[n%i]
    else: ans ^= pre_xor[i] ^ pre_xor[n%i]

fout(ans)