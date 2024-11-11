# -- coding: utf-8 --

binary = input()
n = len(binary)
k = n
for i in range(n - 1):
    if binary[i] != binary[i + 1]:
        k = min(k, max(i, n - i - 1))

print(k)