A, B, K = map(int, input().split())

l = [i for i in range(1, 100) if (A % i == 0 and B % i == 0)]

l = l[::-1]

print(l[K-1])