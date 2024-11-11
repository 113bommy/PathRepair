def rp():
    n=int(input())
    x = [int(x) for x in input().split()] 
    lst=[]
    for i in x:
        if i not in lst:
            lst.append(i)       
    print(*lst,end=" ")
t=int(input())
for i in range(t):
    r=rp()