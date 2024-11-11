n=int(input())
c=0
s=set()
for i in range(1,2*n +1):
    c+=i
    s.add(c%n)

print("yes" if len(s)==n else "no")    

    
    
    
