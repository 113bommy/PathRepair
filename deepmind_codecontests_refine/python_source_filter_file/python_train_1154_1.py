n,m=(int(i) for i in input().split())
a=[int(i) for i in input().split()]
sum=[a[0]]
for i in range(1,n):
    sum.append(a[i]+sum[i-1])
ans=[int(sum[0]/m)]
for i in range(1,n):
    ans.append(int(sum[i]/m)-ans[i-1])

for i in range(n):
    print(f"{ans[i]} ",end="")
    
print()