n=int(input())
lst = list(map(int, input().strip().split(' ')))
print(n+1)
print(1,n,500,end=" ")
print()
for j in range(n):
    print(2,j+1,lst[j]+500-j,end=" ")
    print()