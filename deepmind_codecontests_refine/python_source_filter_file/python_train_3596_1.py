n, x = map(int, input().split())
whoGive, whoTake = x, 0
for i in range(n):
    q = input()
    if q[0] == '-':
        if int(q[-1]) > whoGive:
            whoTake+=1
        else:
            whoGive-=int(q[-1])
    else:
        whoGive+=int(q[-1])
        
print(whoGive, whoTake)