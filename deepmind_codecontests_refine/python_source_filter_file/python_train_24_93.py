t = int(input())
ans = []

def solve(n,arr):
    Max = arr[-1]
    for l in range(n-2):
        if arr[l]+arr[l+1]<=Max:
            answer = [l+1,l+2,n-1]
            return answer
    return [-1]


for i in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    ans.append(solve(n,arr))
for test in ans:
    for num in test:
        print(num,end=" ")
    print()