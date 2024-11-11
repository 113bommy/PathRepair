tq=int(input())
for x in range(tq):
    n,m,x,y=list(map(int,input().split()))
    arr=[]
    for ts in range(n):
        arr.append(list(input()))
    sor=0
    for ps in range(n):
        tp=0
        while (tp<m):
            if (tp<m-1 and arr[ps][tp]=='.' and arr[ps][tp+1]=='.' and y<x):
                sor+=y
                tp+=2
            elif (arr[ps][tp]=='.'):
                sor+=x
                tp+=1
            else:
                tp+=1
    print(sor)
                
                
    
    
        
