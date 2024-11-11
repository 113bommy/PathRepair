def getinput():
    return [int(x) for x in input().strip().split()]


t=int(input())

for t1 in range(t):
    n=int(input())
    interval=[]
    for i in range(n):
        temp=getinput()
        interval.append(temp)
    
    time=1
    for i in range(n):
        if time>interval[i][1]: print(0, end=' ')
        elif time<interval[i][0]:
            print(interval[i][0], end=' ')
            time=interval[i][0]
        else :
            print(time, end=' ')
            time+=1
    print()
        
        