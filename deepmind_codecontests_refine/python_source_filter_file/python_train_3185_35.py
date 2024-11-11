count = 0
limak , bob = map(int,input().split(" "))
while limak>bob:
    count+=1
    limak*=3
    bob*=2
print(count)