def dela(lst, x, k):
    result = x * k
    for i in range(len(lst) - k):
        result += lst[i]
    return result


N, X, K = [int(j) for j in input().split()]
a = [int(z) for z in input().split()]
print(dela(a, X, K))
