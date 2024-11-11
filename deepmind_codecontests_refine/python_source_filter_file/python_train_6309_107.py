n,k = map(int,input().split())
print("YNEOS"[(n/k) % 2 != 0::2])