sa,sb = map(int,input().split())
a,b = map(int,input().split())
print(2 * (max(abs(sa-a)+1, 2) + max(abs(sb-b)+1, 2)))