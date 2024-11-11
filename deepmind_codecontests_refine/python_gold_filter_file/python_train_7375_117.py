N = int(input())
a = sorted(list(map(int, input().split())))[::-1]
print(sum(a[1:2*N:2]))