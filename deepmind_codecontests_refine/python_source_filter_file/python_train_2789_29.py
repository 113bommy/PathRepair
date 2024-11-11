a=int(input())
b=list(map(int,input().split())
 
s=0
for i in range(a):
  for j in range(i+1,a):
    s+=b[i]*b[j]
print(s)