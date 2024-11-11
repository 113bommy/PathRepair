a, b, k = map(int, input().split())
x = [i for i in range(1, min(a, b)+1) if (a % i == 0 and b % i == 0)]
print(x[k-1])
