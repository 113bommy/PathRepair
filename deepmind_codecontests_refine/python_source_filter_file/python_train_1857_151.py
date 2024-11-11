N = int(input())
a = list(map(int, input().split()))
b = sorted(a)[:: -1]
print(sum(b[:: 2]) - sum(a[1:: 2]))
