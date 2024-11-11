N = int(input())
As = list(map(int, input().split()))

As.sort()

print(sum(As[N:2*N]))
