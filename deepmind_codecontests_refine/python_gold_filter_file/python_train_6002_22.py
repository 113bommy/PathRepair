n,m=input(). split()
n=int(n)
m=int(m)
i=1
a=m%(n*(n+1)//2)
while a>=i:
    a=a-i
    i=i+1
print(a)
 
   
   
   

    








