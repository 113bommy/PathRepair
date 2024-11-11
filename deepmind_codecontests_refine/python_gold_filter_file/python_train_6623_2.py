def dela(lst, k, x):
    result = x * k
    for i in range(len(lst) - k):
        result += lst[i]
    return result


N, K, X = [int(j) for j in input().split()]
a = [int(z) for z in input().split()]
print(dela(a, K, X))
