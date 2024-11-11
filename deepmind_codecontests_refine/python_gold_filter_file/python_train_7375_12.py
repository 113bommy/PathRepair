n = int(input())
a = sorted(map(int, input().split()))
print(sum(a[n::2]))