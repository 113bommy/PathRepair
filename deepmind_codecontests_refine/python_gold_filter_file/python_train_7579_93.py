n,k=map(int,input().split())
l=sorted([int(input()) for i in range(n)])
print(min([abs(l[i]-l[i+k-1]) for i in range(n-k+1)]))