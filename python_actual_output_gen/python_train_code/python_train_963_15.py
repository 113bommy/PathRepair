n = int(input())
arr = list(map(int, input().split()))

crimes = 0
police = 0

for i in arr :
    if  i >= 1:
        police += 1
    if i == -1:
        if police :
            police-= 1
        else :
            crimes += 1
print(crimes)
    