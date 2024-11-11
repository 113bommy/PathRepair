alc=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
al=['0','1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17']
ans=0
a=int(input())
for _ in range(a):
    x=input()
    if(x in al or x in alc):
        ans+=1
print(ans)