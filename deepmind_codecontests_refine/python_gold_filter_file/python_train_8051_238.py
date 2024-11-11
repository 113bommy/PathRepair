n=int(input())
j= list(map(int, input().split()))
k=0
for i in range(n):
    k=k+j[i]
print(k/n)