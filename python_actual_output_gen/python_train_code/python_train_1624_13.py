n=int(input())
a=sorted([list(map(int,input().split())) for i in range(n)])
print(sum(a[0]))