n=int(input())
a=0
for i in range(2,int(n**.5+1)):t=n//i-1;a+=t*(i==n%t)
print(a)