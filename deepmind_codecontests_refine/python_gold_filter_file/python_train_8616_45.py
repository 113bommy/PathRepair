# フェルマーの小定理
K = int(input())
S = input()

m = 1000000007

result = 0
a = 1
b = 1

for i in range(K + 1):
    # result += pow(26, K - i, m) * mcomb(len(S) - 1 + i, i) * pow(25, i, m)
    result += pow(26, K - i, m) * (a * pow(b, m - 2, m)) * pow(25, i, m)
    result %= m
    a *= len(S) - 1 + (i + 1)
    a %= m
    b *= i + 1
    b %= m
print(result)
