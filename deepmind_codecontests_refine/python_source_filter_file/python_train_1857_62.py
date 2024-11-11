N=int(input())
a = sorted(map(int, input().split()))
print(abs((sum(a[1::2]) - sum(a[::2])))