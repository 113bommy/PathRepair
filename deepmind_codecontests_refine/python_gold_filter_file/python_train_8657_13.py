mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())

def checkap(arr):
    d=arr[1]-arr[0]
    for i in range(len(arr)-1):
        if arr[i]+d!=arr[i+1]:
            return False
    return True

def main():
    n=ii()
    l=il()
    arr=sorted(l)
    if checkap(arr) or checkap(arr[1:]):
        print(l.index(arr[0])+1)
        exit(0)
    if checkap(arr[:1]+arr[2:]):
        print(l.index(arr[1])+1)
        exit(0)
    d = arr[1] - arr[0]
    ind=-1
    for i in range(n-1):
        if arr[i]+d!=arr[i+1]:
            ind=i+1
            break
    if checkap(arr[:ind]+arr[ind+1:]):
        print(l.index(arr[ind])+1)
    else:
        print(-1)

main()