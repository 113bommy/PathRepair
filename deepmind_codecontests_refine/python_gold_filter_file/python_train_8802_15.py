a=list(map(int,input().split()))
print(sum(max(0,max(a)-x-1)for x in a))