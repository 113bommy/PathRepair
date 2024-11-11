'''def find_max(a,low,mid,high):
    leftsum = -1
    s = 0
    for i in range(mid,low,-1):
        s = s+a[i]
        if s>leftsum:
            leftsum = s
            maxleft = i
    rightsum = -1
    s = 0
    for j in range(mid+1,high):
        s = s+a[j]
        if s>rightsum:
            rightsum = s
            maxright = j
    return (maxleft,maxright,leftsum+rightsum)

def find(a,low,high):
    if high == low:
        return low,high,a[low]
    else:
        mid = (low+high) // 2
        leftlow,lefthigh,leftsum = find(a,low,mid)
        rightlow,righthigh,rightsum = find(a,mid,high)
        crosslow,crosshigh,crossum = find_max(a,low,mid,high)
        if leftsum>=rightsum and leftsum>=crossum:
            return leftlow,lefthigh,leftsum
        elif rightsum>=leftsum and rightsum>=crossum:
            return rightlow,righthigh,rightsum
        else:
            return crosslow,crosshigh,crossum

a = [-1,5,9,-4,-2,5,6,-5]
low = 0
high = len(a)
mid= len(a)//2
'''
t = int(input())
arr = list(map(int,input().split(' ')))
arr.append(-1)
x = 1
r = -1
for i in range(1,t):
    if arr[i]>=arr[i-1]:
        x+=1
    else:
        r = max(r,x)
        x=1
print(max(r,x))

