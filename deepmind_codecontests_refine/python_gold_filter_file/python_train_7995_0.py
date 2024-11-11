n,m=map(int,input().split())
x=sorted([int(i)for i in input().split()])
l=sorted([x[i+1]-x[i]for i in range(m-1)])
print(sum(l[:m-n])if m>n else 0)