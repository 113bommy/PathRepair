n = int(input())
a = [int(s) for s in input().split()]

x = max(a)
maxlen = -10**10
leng = 0
for i in range(1, len(a)):
    if a[i] == x:
        leng += 1
    elif a[i] != x:
        if leng > maxlen:
            maxlen = leng
        leng = 0

if leng > maxlen:
        maxlen = leng
print(maxlen)
