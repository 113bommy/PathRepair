n = int(input())
prev = -1
for x in input().split():
    temp = int(x)
    while(temp%2==0):
        temp = temp//2
    while(temp%3==0):
        temp = temp//3
    if prev!=-1:
        if temp!=prev:
            print("N0")
            break
    else:
        prev = temp
else:
    print("Yes")
