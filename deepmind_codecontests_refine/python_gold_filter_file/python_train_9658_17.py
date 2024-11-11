input()
a = list(map(int, input().split()))

print(sum([ai % 2 for ai in a[::2]]))