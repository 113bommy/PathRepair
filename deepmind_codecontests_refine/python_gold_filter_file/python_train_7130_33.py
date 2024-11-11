n=int(input())
a=set(['ABSINTH','BEER','BRANDY','CHAMPAGNE','GIN','RUM','SAKE','TEQUILA','VODKA','WHISKEY','WINE'])
c=0
for i in range(n):
    s=input()
    if s.isdigit():
        if int(s)<18:c+=1
    else:
        if s in a and s.isalpha():c+=1
print(c)
