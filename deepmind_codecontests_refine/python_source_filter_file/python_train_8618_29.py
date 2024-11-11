n, k = map(int,input().split())
print(len([*filter(lambda hi: hi >= k, map(int,input().split()))]))