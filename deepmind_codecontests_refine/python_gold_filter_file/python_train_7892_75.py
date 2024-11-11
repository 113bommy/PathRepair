L=list(map(int,input().split()))
K=int(input())
m=max(L)
print(sum(L)-m+m*2**K)