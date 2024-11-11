I,R=input,range
n=int(I())
s=[I()for i in R(n)]
a=0
for i in R(n):
 if all(s[(i+j)%n][k]==s[(i+j)%n][j]for j in R(n) for k in R(i+1,n)):a+=n
print(a)