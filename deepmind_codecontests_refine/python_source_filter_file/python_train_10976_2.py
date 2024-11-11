n, k = map(int, input().split())
print(len(list(filter(lambda w: w>=k, map(int, input().split()))))//3)