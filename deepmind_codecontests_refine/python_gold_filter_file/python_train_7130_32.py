n=int(input())
count=0
lst=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE','0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17']
for i in range(n):
    temp=input()
    if(temp in lst):
        count+=1
print(count)