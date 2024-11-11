n, k = map(int,input().split())
print(len(list(filter(lambda hi: hi >= k, map(int,input().split())))))