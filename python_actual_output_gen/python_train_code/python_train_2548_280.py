N = int(input())
a = sorted(list(map(int, input().split())))
print(sum(a[N:2 * N]))