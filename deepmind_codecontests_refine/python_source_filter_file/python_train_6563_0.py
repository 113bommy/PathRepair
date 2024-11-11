n = int(input())
a = list(map(int, input().split(' ')))

a = list(set(a))
print(' '.join(list(map(str, a))))
