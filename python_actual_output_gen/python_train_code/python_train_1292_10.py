n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=[map(int,input().split()) for _ in range(m)]
for i in b:
    print(sum(a)-a[i[0]]+i[1])