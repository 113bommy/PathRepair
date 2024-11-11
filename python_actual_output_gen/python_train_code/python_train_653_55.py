N = input()
a = sorted(map(int,input().split()))
print(sum(a[::2]) - sum(a[1::2]))