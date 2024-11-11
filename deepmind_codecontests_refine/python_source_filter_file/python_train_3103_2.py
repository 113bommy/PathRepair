N = int(input())
W =[int(x) for x in input().split()]
print(min(abs(sum(W[:i])-sum(W[i:])) for i in range(N))