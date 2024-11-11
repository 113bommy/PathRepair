l=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA','VODKA', 'WHISKEY', 'WINE']
n=int(input())
c=0

while(n):
    n-=1
    a=input()
    if( a.isnumeric() ):
        if(int(a)<18):
            c+=1
    
    elif a not in l:
       
        c+=1
   
print(c)
    