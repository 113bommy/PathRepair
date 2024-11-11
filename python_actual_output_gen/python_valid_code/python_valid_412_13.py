n,a,b=input().split()
a=int(a)
b=int(b)
n=int(n)
l=[]

for i in range(1,n-1):
   
    num=min(a/i,b/(n-i))
    l.append(num)
    
l.sort()

print(int(l[-1]))