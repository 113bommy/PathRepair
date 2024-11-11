n=int(input());a=list(map(int,input().split()))
c,res=0,0
for i in range(n):
    c=[2,c+1][i<2 and a[i]==a[i-1]+a[i-2]]
    res=max(res,c)
print(res) 
