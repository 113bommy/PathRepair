# your code goes here
t = int(input())
a = input()
b = input()
sum = 0
for i in range(t):
    if((abs((int(b[i])-int(a[i])))>0) and (abs((int(b[i])-int(a[i])))<=5)):
        sum = sum + abs((int(b[i])-int(a[i])))
    else:
        sum = sum + (10-abs((int(b[i])-int(a[i]))))
    
print(sum)