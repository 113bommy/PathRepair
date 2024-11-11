n,k = map(int,input().split())
h = list(map(int,input().split()))
print(len([0 for x in h if x >= k]))