n=int(input())
a=0
for i in range(1,n+1):
 a+=(i+(n//i)*i)*(n//i)//2
print(a)