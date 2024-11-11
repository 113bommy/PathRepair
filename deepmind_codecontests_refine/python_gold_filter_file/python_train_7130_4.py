compare= ["ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"]
countaw=0
myList=[]
x=int(input())
for j in range (0,x):
    g=input()
    myList.append(g)
for i in myList:
    for j in compare:
        if i==j:
            countaw+=1
            break
        else:
            if ord(i[0])>=48 and ord(i[0])<58:
                if int(i)<18:
                                     countaw+=1
                                     break
                                     
            
    
print (countaw)
