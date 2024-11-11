def sum(n):
    arr=str(n)
    arr=list(arr)
    arr=[int(x) for x in arr]
    ans=0
    for x in arr:
        ans+=x
    return ans

k,sumx=map(int,input().split())
if(k==1 and sumx==0):
    print(0)
elif(sumx==0):
    print("No solution")
else:
    ans=str(sumx)+"0"*(k-1)
    print(ans)
