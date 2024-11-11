n,m,z = map(int , input().split(' '))
i=1
ilia=a=c=0 
while i <= z:
    a= i*n
    if a % m == 0 and a <= z:    
      c+= 1
    i+= 1
print(c)