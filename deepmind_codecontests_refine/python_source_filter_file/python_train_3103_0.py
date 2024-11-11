n = int(input())
w = [int(i) for i in input().split()]
d = [abs(sum(w[:i])-sum(w[i:])) for i in range(1, n-1)]
print(min(d))