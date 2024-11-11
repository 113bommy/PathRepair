n, k = list(map(int, input().split()))
print(min((k-1)//2,n)-max(k-n,1)+1)
