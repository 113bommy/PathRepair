S=int(input())
h=S/3600
k=S%3600
m=k/60
s=k%60
print("%d:%d:%d" %(h,m,s))