import random
n=int(input())
c=""
k=0
l=['a','b']
while(len(c)<n):
    c=c+(k+1)*l[k%2]
    k+=1
print(c[0:n])
    
