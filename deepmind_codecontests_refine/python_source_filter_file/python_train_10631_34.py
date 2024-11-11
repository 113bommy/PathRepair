n = int(input())
l = list(map(int,input().split()))
print(n+1)
print(1,n,n+1)
for j in range(n):
    print(2,j+1,l[j]+n+1-j)