n=int(input())
cnt=0
for i in range(n,0,-1):
    s=input()
    if(s=='0'or s=='1' or s=='2' or s=='3' or s=='4' or s=='5' or s=='6' or s=='7' or s=='8' or s=='9'or s=='10'or s=='11'or s=='12'or s=='13'or s=='14'or s=='15'or s=='16'or s=='17'or s=='ABSINTH' or s== 'BEER' or s=='BRANDY'or s=='CHAMPAGNE' or s=='GIN' or s=='RUM' or s=='SAKE' or s=='TEQUILA' or s=='VODKA' or s=='WHISKEY' or s=='WINE'):
        cnt+=1
print(cnt)
