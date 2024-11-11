n = int( input())
k = int( input())

a = 1
for i in range(k+1):
  a = min(a+k, a*2)  
print(a)