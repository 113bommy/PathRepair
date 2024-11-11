input()
a = list(map(int, input().split()))

sum([ai % 2 for ai in a[::2]])