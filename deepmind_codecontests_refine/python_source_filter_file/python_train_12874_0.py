n = int(input())
a = [int(x) for x in input().split(' ')]

s = set(a)
print(s)
print(len(s) - int(0 in s))