n=int(input())
l=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
count=0
for i in range(n):
    k=input()
    if(k.isdigit()==True):
        if(int(k)<18):
            count+=1
    else:
        if(k not in l):
            count+=1
print (count)