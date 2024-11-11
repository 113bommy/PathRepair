n = int(input())
arr = [int(x) for x in input().split()]
arr.sort()
for i in arr:
    print(i, end="")
    