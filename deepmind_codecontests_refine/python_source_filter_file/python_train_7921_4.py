# https://codeforces.com/problemset/problem/1034/B
n, m = map(int, input().split())

min_, max_ = min(n, m), max(n, m)
arr1 = [1,2,3,2,1,0]
arr2 = [2,4,2]
if min_ == 1:
    r=arr1[(max_-1)%6]
elif min_ == 2:
    if max_<=3:
        r=arr2[max_-1] 
    else:
        r=0
else:
    r=(n*m)%2
    
print(n*m-r)    