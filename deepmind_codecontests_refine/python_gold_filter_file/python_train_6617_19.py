R = lambda:list(map(int, input().split(' ')))
#r, w = open("input.txt", "r"), open("output.txt", "w")
n, n1, n2 = R()
a = R()
a.sort()
if n1 > n2:
    k = n1
    n1 = n2
    n2 = k
sum1 = sum([a[i] for i in range(n - n1, n)])
sum2 = sum([a[i] for i in range(n - n1 - n2, n - n1)])
sum1 /= (n1 + 0.0)
sum2 /= (n2 + 0.0)
print(sum1 + sum2)
