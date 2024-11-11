S=int(input())
h=S/3600
k=S//3600
m=k/60
s=k-m
print("%d:%d:%d" %(h,m,s))