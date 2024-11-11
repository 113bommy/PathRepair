n = int(input())
i = n+1
while i<=9000 :
    if len(str(i)) == len(set(str(i))) :
        print(i)
        break
    i += 1