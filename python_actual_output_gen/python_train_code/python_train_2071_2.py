r, s = map(int, input().split())
k = 1
truth = True
while truth == True:
    k=1
    while k <= s:
        if r-s <= 0:
            truth = False
            break
        else:
            r-=k
            k+=1
print(r)
