import sys
input=sys.stdin.readline
for _ in range(int(input())):
    n=int(input())
    arr=[int(j) for j in input().split()]
    arr.sort()
    if sum(arr[0:-1])<2*max(arr):
        print("T")
    else:
        if sum(arr)%2!=0:
            print("T")
        else:
            print("HL")


