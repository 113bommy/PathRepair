n = int(input())
l = ['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY','WINE']
l1 = ['0,''1','2','3','4','5','6','7','8','9']
c = 0
for i in range(n):
  s = str(input())
  if s in l:
    c+=1
  elif s[0] in l1:
    if(int(s) < 18):
      c+=1
print(c)        







