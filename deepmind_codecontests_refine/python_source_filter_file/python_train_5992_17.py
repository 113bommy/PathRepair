n = int(input())
arr = list(map(int,input().split()))
s = sum(arr)//n
s *= 2
memo = {i:False for i in range(n)}
for i in range(n):
    if memo[i] == False:
        for j in range(i+1, n):
            if memo[j] == False and arr[j] == s - arr[i]:
                memo[j] = True
                memo[i] = True
                break
        print(i+1,j+1)
