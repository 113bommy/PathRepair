N = int(input())
a = sorted(list(map(int, input().split())))[::-1]
print(sum(a[N:2*N]))
