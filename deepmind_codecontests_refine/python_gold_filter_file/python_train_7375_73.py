n = int(input())
a = sorted(map(int, input().split()))

print(sum(a[n:3*n+1:2]))