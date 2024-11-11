n = input()
a = sorted(list(map(int, input().split())), reverse=True)
print(sum(a[::2] - a[1::2]))