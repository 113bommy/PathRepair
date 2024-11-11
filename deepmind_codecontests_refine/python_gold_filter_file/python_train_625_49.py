a, b, c = map(int, input().split())

X = [i for i in range(a,b+1) if c % i == 0]
print(len(X))
