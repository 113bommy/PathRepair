n = int(input())
arr = list(map(int,input().split()))
arr.sort()
sm = sum(arr)
if ((arr[-1] * 2) < sm) and (sm % 2 == 0):
    print("YES")
else:
    print("NO")

