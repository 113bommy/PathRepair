def fact(n):
    facto = 1
    m = n
    while(m>0):
        facto = facto*m
        m-=1
    return facto    
        
n = int(input())
if(n%2 == 0 and n>=2 and n<=20):
    l = (fact(n)/(2*pow(fact(n/2),2)))*pow(fact(n/2 - 1),2)
    print(l)
