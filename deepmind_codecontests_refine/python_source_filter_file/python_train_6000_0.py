sa,sb = map(int,input().split())
a,b = map(int,input().split())
print(2 * (max(abs(sa-sb)+1, 2) + max(abs(a-b)+1, 2)))