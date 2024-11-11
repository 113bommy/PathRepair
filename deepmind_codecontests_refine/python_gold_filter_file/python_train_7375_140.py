n = int(input())
a = list(map(int, input().split()))
a.sort()
print(sum(i for i in a[n::2]))