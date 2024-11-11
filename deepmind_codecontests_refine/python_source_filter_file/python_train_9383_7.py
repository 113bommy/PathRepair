n, k, m = map(int, input().split())
a = map(int, input().split())
b = sorted(a)
sum_b = sum(b)
len_b = len(b)
res = sum_b / len_b + min(m, len_b * k) / len_b
for i in range(min(m, n-1)):
    sum_b -= b[i]
    len_b -= 1
    res = max(res, sum_b/len_b+min(m, len_b*k) / len_b)
print(res)