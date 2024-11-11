def shifts(arr):
    steps=[]
    req = sorted(arr)
    while(arr!=req):
        nomat,ind = nonmatch(arr,req)
        shift = ind-nomat
        changed = [arr[ind]]
        changed.extend(arr[nomat:ind])
        arr[nomat:ind+1] = changed
        steps.append([nomat,ind,shift])
    return steps
def nonmatch(arr,req):
    curr=-1
    for i in range(len(arr)):
        if(arr[i]!=req[i]):
            curr = i
            break
    nex = -1
    for i in range(curr,len(arr)):
        if(arr[i]==req[curr]):
            nex = i
    return (curr,nex)
for j in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    steps = shifts(arr)
    print(len(steps))
    for i in steps:
        print(f"{i[0]+1} {i[1]+1} {i[2]+1}")