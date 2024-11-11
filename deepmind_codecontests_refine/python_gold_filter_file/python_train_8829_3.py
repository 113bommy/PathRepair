N = int(input())
A = [int(i) for i in input().split()]

X = [a-(i+1) for i, a in enumerate(A)]
X.sort()
b = X[(N)//2]
print(sum([abs(x - b) for x in X]))