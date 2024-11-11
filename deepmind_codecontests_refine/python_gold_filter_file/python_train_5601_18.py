N = int(input())
A = map(int, input().split())
print(1 / sum(1 / x for x in A))