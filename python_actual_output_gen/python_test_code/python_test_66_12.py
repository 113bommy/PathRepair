n = int(input())
str = input()
collider = input().split(' ')
min = -1
for i in range(n-1):
    y = int(collider[i])
    z = int(collider[i + 1])
    if((str[i] == "R") and (str[i+1] == "L")):
        if(min > -1):
            if((z-y)/2 > min):
                min = (z-y)/2
        if(min == -1):
            min = (z-y)/2
print(int(min))