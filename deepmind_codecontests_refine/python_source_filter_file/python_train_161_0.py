x = int(input(""))
x = hex(x)[2:]
one = ['0', '4', '6', '9', 'a', 'c']
two = ['8', 'b']
count = 0
for i in x:
    if(i in one):
        count += 1
    elif(i in two):
        count += 2
print(count)
