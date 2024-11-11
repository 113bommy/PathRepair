n = int(input())
a = map(int, input().split())
print (max(a) * 2 - sum(a) + 1)