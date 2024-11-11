y=int(input())
y=y+1
while len(set(str(y)))<4:
    y+=1
print (y)