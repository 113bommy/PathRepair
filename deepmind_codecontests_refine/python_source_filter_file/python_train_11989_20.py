from math import factorial 
n = int(input())
l = []

for i in range(n):
    st = input()
    l.append(st[0])
    
def fact(j):
    if j == 1:
        return 0
    else:
        return (factorial(j) // (factorial(j - 2) * 2))
    
se = set(l)
total = 0
for i in se:    
    co = l.count(i)
    if co > 1:
        
        if co % 2 == 0:
            c1 = co // 2
            total += fact(c1)
        
        else:
            c2 = co // 2
            c3 = (co + 1) // 2
            total += fact(c2)
            total += fact(c3)
                   
                  
print(total)
                   
   

                  
                 
                  
                  
        
   
                  
    
                  
                  

   
        

   
   