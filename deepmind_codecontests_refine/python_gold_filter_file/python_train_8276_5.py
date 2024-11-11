c,m=map(int,input().split(':'))
m1=int(input())
M=c*60+m+m1
c=M//60
if c>=24:c=c%24
m=M%60
print(c//10,c%10,':',m//10,m%10,sep='')