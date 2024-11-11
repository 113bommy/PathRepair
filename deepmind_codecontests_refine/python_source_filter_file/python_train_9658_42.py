n = int(input())
a = list(map(int, input().split()))

a = list(filter(lambda x: x % 2 == 1, a[1::2]))
print(len(a))