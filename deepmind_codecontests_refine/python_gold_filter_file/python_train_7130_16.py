x=['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
c=0
num='0123456789'
for _ in range(int(input())):
  y=input()
  if y[0] in num:
    if int(y)<18:
      c+=1
  elif y in x:
    c+=1
print(c)