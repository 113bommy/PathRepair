l = map(int,input().split())

officers = 0
crimes = 0
for i in l:
    if i==-1:
        if officers:
            officers-=1
        else:
            crimes+=1
    else:
        officers+=i

print(crimes)
