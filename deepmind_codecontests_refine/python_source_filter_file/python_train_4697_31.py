
def ok(arr1):
    arr1.sort()
    if arr1[2]-arr1[0]-arr1[1]<=0:
        return 0
    else:
        return arr1[2]-arr1[0]-arr1[1]+1
arr1=list(map(int,input().split()))
print(ok(arr1))