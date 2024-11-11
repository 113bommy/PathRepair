n=int(input())
l=list(map(int,input().split()))
k=360
for i in range(n):
    for j in range(i,n):k=min(k,abs(sum(l[i:j])))
print(k)