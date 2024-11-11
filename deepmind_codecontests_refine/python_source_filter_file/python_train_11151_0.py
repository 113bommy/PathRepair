n,m = map(int,input().split())
a = input()[::-1]
b = input()[::-1]
c = 0
f = b.count('1')
wer = 1
for i in range(min(m,n)):
    if a[i] == '1':
        c += f * wer
        c %= 9982443530
    if b[i] == '1':
        f -= 1
    wer *= 2
    wer %= 998244353
print(c)
