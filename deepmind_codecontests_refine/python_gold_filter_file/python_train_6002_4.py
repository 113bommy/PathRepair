r, s = map(int, input().split())
k = 1
truth = True
while truth == True:
    k=1
    while k <= r:
        if s-k < 0:
            truth = False
            break
        else:
            s-=k
            k+=1
print(s)
