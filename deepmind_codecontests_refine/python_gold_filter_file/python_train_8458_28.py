from sys import stdin
for i in range(int(input())):
    n=int(input())
    arr = list(map(int, input().split()))
    arr= list( dict.fromkeys(arr))
    print(*arr)
    