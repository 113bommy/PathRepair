n = int(input())
a = list(map(int, input().split(' ')))
m = int(input())
b = list(map(int, input().split(' ')))

if set(a).issubset(set(b)):
    print(1)
else:
    print(0)
