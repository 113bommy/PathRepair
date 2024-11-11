n,m = input().split()
n=int(n)
m=int(m)

if(m-1>=n-m and m!=1):
    print(m-1)
elif(m==1):
    print(1)
else:
    print(m+1)
