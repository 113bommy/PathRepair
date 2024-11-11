testcases=int(input())
MOD=(10**9)+7
for _ in range(testcases):
    x=int(input())
    initialstring=list(map(int,input()))
    initiallength=len(initialstring)
    slicecounter=1
    while slicecounter<=x:
        numberatend=initialstring[slicecounter-1]
        initiallength=(initiallength+(initiallength-(slicecounter))*(initialstring[slicecounter-1]-1))%(MOD)
        idx=len(initialstring)
        for _ in range(numberatend-1):
            if len(initialstring)<x+1:
                initialstring+= initialstring[slicecounter:]
            else:
                break
        slicecounter+=1
    print(initiallength%MOD)