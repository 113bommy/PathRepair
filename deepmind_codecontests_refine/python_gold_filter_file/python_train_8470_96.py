n = int(input())
i = n+1
while True :
    if len(str(i)) == len(set(str(i))) :
        print(i)
        break
    i += 1