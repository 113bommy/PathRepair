n=int(input())
a=list(map(int,input().split))
print(min([abs(sum(a[:i])-sum(a[i:]))for i in range(n)]))