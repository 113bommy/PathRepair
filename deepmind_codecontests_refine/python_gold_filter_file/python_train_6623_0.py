n, k, x = map(int, input().split())
l = sorted([int(i) for i in input().split()])[::-1]

lst = l[k:]

print(sum(lst) + k*x)

