l=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
n=int(input())
ans=0
for x in range(n):
    x=input()
    if x.isnumeric():
        x=int(x)
        if x<=17:
            ans+=1
    else:
        if x not in l:
            ans+=1
print(ans)