n=int(input())
l1=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
ans=0
for i in range(n):
    s=input()
    if ord(s[0])<65:
        if(int(s))<18:
            ans+=1
    else :
        if s not in l1:
            ans+=1
print(ans)