X,N=map(int,input().split())
p=sorted(map(int,input().split()))
diff=101
for i in range(101):
    if i not in p and abs(X-i)<diff:
        diff=abs(X-i)
        ans=i
print(ans)