N = int(input())
a = list(map(int, input().split()))
a.sort()
print(sum(a[N:N*2]))