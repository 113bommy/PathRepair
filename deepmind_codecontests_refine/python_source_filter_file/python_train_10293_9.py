N = input()
A = list(map(int, input().split()))

num = -(-sum(A) // len(A))
cost = [(a - num)**2 for a in A]

print(sum(cost))