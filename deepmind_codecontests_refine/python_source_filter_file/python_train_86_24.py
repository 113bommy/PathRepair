ans=["NO","YES"]
candy=list(map(int,input().split()))
print(ans[sum(candy)/2 in candy])
