n=''
a=input()
for i in a:
    if(i==">"):
        n=n+'1000'
    if(i=="<"):
        n=n+'1001'
    if(i=="+"):
        n=n+'1010'
    if(i=="-"):
        n=n+'1011'
    if(i=="."):
        n=n+'1100'
    
    if(i==","):
        n=n+'1101'
    
    if(i=="["):
        n=n+'1110'
        
    if(i=="]"):
        n=n+'1111'
        
x=int(n, 2)
print(x)