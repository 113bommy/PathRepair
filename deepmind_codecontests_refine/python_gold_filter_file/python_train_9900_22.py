n, k = list(map(int, input().split()))
print(max(0,min((k-1)//2,n)-max(k-n,1)+1))
