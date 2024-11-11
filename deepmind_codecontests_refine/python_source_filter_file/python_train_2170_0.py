N = int(input())
a = map(int, input().split())
tmp = 3 ** N
g = len([c for c in a if a % 2 == 0])
print(tmp - (2 ** g))