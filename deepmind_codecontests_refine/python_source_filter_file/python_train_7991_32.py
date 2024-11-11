from math import modf
n, k, *A = map(int, open(0).read().split())
t = sum(A) / (n+k)
A = [a for a in A if int(a/t) >= 1]
c = k - sum(int(a/t)-1 for a in A)
X = []
for a in A:
    X.append(ceil(a / ceil(a/t)))
    X.append(ceil(a / int(a/t)))
X.sort()
print(X[-c-1])