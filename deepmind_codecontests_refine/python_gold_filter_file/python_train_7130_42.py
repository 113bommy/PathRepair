n=int(input())
a=[]
b=["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]
c=list(range(0,18))
c=[str(i) for i in c]
count=int(0)
for i in range(n):
    a.append(input())
    if(a[i] in b):
        count=count+1
    elif(a[i] in c):
        count=count+1
print(count)