n=int(input())
list=["ABSINTH","BEER",'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA','VODKA', 'WHISKEY','WINE' ]
list1=[f'{i}' for i in range(18)]
c=0
for i in range(n):
    a=input()
    if a in list or a in list1:
        c+=1
    else:
        pass
print(c)