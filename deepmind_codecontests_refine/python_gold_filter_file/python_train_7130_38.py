t = int(input())
age=[]
wine=[]
w=["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]
for i in range(t):
    s = input()
    if s.isdigit()==True:
        age.append(s)
    else:
        wine.append(s)
cnt=0


for i in age:
    if int(i)<18:
        cnt+=1
for i in wine:
    if i in w:
        cnt+=1
print(cnt)