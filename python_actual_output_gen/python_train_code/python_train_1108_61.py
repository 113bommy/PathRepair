list1 = input().split()
limak, bob = int(list1[0]), int(list1[1])
x = 1
while limak < bob:
    limak +=3
    bob +=2
    x +=1
print(x)