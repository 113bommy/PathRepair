a,b,c=[int(x) for x in input().split()]
ans=[]
for i in range(1,73):
    x=b*pow(i,a)+c
    n=x
    ds=0
    while(n>0):
        ds+=n%10
        n=n//10
    if ds==i and x>0 and x<1000000000:
        ans.append(x)
print(len(ans))
print(*ans)