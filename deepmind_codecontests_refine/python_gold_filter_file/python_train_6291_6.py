from collections import Counter
def solve():
    n=int(input())
    queue=[int(i) for i in input().split()]
    Min,sum=10**6,0
    for i in range(n):
        arr=[int(i) for i in input().split()]
        sum=15*queue[i]
        for i in arr:
            sum+=i*5
        Min=min(sum,Min)

    return Min



    





print(solve())

