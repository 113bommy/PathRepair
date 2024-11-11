import sys
n,k=[int(x) for x in sys.stdin.readline().strip().split()]
arr=[int(x) for x in sys.stdin.readline().strip().split()]
if max(arr)-min(arr)>k: print("NO")
else:
    print("YES")
    for i in arr:
        for j in range(1,i+1): print(j,end=" ")
        print("")
