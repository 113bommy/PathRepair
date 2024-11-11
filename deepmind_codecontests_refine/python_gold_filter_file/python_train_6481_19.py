'''Author- Akshit Monga'''
import sys
# input=sys.stdin.readline
t = int(input())
for _ in range(t):
    n=int(input())
    arr=[int(x) for x in input().split()]
    if n%2!=0:
        pivot=-1
        for i in range(n):
            if arr[i]!=1:
                pivot=i
                break
        if pivot==-1 or pivot==n-1:
            print("First")
            continue
        if pivot%2==0:
            print("First")
        else:
            print("Second")
        continue
    else:
        pivot = -1
        for i in range(n):
            if arr[i] != 1:
                pivot = i
                break
        if pivot == -1 or pivot == n - 1:
            print("Second")
            continue
        if pivot % 2 == 0:
            print("First")
        else:
            print("Second")
        continue