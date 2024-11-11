a,b,k=map(int,input().split());r=range(a,b+1)
for i in sorted(set(r)-set(r[k:-k])):print(i)