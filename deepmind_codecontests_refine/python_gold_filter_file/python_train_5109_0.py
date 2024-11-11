n = int(input())
a = list(map(int, input().split(' ')))
m = int(input())
b = list(map(int, input().split(' ')))

if set(b).issubset(set(a)):
    print(1)
else:
    print(0)
