n=int(input())
s=input()
t=input()
for i in range(n):
 if s[-i-1:]==t[:i+1]:
  cnt=i+1
print(2*n-cnt)