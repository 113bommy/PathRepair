A, B, K = map(int, input().split())

l = range(A, B+1)
a = [n for n in l[:K]]
b = [n for n in l[-K:]]

for n in set(a + b):
    print(n)
