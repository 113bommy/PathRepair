n = int(input())
arr = list(map(int, input().split()))

def sol(n):
    arr.sort()
    if arr[0] == arr[-1]:
        return '-1'
    else:
        print(*arr)
        
        
sol(n)