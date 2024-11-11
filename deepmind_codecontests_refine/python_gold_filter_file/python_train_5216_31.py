n, a = int(input()), list(map(int, input().split())) + [10 ** 10]

i = 0
j = 1
maxlen = 0

while j < len(a):
    if a[j - 1] * 2 < a[j]:
        maxlen = max(maxlen, j - i)
        i = j
    j += 1

print(maxlen)
