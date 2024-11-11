import sys
def solve(arr,bit):
    #print(arr,bit)
    if len(arr)==0 or bit<0:
        return 0
    l,r=[],[]
    for i in range(len(arr)):
        if (arr[i]>>bit)&1==0:
            l.append(arr[i])
        else:
            r.append(arr[i])
    if len(l)==0:
        return solve(r,bit-1)
    if len(r)==0:
        return solve(l,bit-1)
    return min(solve(l,bit-1),solve(r,bit-1))+1<<bit
n=int(sys.stdin.readline())
l=list(map(int,sys.stdin.readline().split()))
print(solve(l,30))
