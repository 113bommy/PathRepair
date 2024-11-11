n = int(input())
arr = list(map(int, input().split()))
if (max(arr)<=sum(arr) and sum(arr)%2==0):
    print("YES")
else:
    print("NO")
