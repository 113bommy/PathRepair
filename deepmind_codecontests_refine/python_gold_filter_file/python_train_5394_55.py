n=int(input())
l=sorted(map(int,input().split()))
print(['No','Yes'][l[-1]<sum(l)-l[-1]])