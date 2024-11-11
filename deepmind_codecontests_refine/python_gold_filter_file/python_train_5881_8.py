a = int(input())
ori = [i for i in input()]
change = [i for i in input()]

combi = list(zip(*[ori,change]))

    


check = 0
for i in range(len(combi)):
    m = int(combi[i][0])
    n = int(combi[i][1])
    v = int(combi[i][0]) - int(combi[i][1])
    if abs(v) <= 5:
            #print(int(combi[i][0]), int(combi[i][1]))
            check+=abs(v)
    if abs(v) >5 :
        if m < n:
            
            check +=abs((m+10)-n)
        else:
            check+=abs(m-(n+10))
print(check)            
        