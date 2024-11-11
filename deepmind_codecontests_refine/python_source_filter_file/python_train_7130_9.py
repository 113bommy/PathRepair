l=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
n= int(input())

r= [str(k) for k in range(1,18)]

l= l+r
ans=0
for i in range(n):
    t= input()
    
    if t in l:
        ans+=1
print(ans)
