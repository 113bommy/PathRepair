t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    odd,even = [],[]
    for i in range(2*n):
        if arr[i]%2 == 0:
            even.append(i)
        else:
            odd.append(i)
    ans = []
    count = 0
    while(count!=(n-1)):
        if len(odd)>=2:
            ans.append([odd.pop(),odd.pop()])
            count += 1
        elif(len(even)>=2):
            ans.append([even.pop(),even.pop()])
            count += 1
    for u,v in ans:
        print(u,v)