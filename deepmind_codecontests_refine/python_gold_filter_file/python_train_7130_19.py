string = '18'
def func(T,k1):
    l1 = []
    count = 0
    b = 0
    for i in range(0,k1):
        j = str(input())
        l1.append(j)
        
   
    for i in l1:
        for d in T:
            if i == d:
                count+=1
                
                
    for i in l1:
        if i.isdigit():
            if int(i) < int(string):
                b+=1         
     
    g = count + b
    return g
                
    
                
L = ["ABSINTH","BEER","BRANDY","CHAMPAGNE","GIN","RUM","SAKE","TEQUILA","VODKA","WHISKEY","WINE"]
k = int(input())          
h = func(L,k)  

print(h)         
