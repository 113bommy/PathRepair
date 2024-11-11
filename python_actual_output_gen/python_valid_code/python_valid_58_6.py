x = 0
limit = int(input())
count = 0
while limit > count:
    user = input()
    if (user == "++x") or (user == "x++"):
        x += 1  
    elif (user == "--x") or (user =="x--"):
        x -= 1
    count += 1
print(x)