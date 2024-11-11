r,c=[int(x) for x in input().split()]
cake=[]
for i in range(0,r):
    cake.append(input())


number = 0
notrows = 0
for row in cake:
    
    if 's' not in row:
        number += c
        notrows += 1

for column in range(0,c):
    find = False
    for row in cake:
        if row[column]=='s':
            find=True
    if not find:
        number += r - notrows
    
print(number)
