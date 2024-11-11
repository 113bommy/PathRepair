a,b,c=map(int, input().split())

k=0
for j in range(a+1,b):
     if c%j==0:
          k+=1

print(k)
     
