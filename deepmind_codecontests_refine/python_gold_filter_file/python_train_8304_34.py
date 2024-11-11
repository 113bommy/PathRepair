h,n = map(int,input().split())
al = list(map(int,input().split()))

print(['No','Yes'][sum(al)>=h])