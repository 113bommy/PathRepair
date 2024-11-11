l,r = map(int,input().split())
i = l
count = 0
while i != r:
    j = str(i)
    if len(j) == len(set(j)):
        print(i)
        count = 1
        break
    else:pass    
    i+=1
if count == 0:
    print(-1)