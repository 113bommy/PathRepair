n = int(input())
a = [int(s) for s in input().split(' ')]
print(max(max(a) - 25, 0))