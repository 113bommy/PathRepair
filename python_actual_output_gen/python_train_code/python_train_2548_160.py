N = int(input())
a = list(map(int, input().split()))
a = sorted(a, reverse = True)

print(sum(a[N:2*N]))
