t = int(input())
for i in range(t):
    n, p, q = [int(w) for w in input().split()]
    answer = n - max(p, q) + 1
    print(answer)