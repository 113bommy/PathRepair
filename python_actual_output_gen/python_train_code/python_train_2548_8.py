N = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
print(sum(a[N - 1:2 * N:2]))