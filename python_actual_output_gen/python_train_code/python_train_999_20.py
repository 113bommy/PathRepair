n = int(input())
arr = list(map(int, input().split()))
cc = 2
i = 0
ans = 2
while i < n-2:
    temp = arr[i]
    temp2 = arr[i+1]
    temp3 = arr[i+2]
    if temp+temp2 == temp3:
        cc += 1
        if cc > ans:
            ans = cc
    else:
        cc = 1
    i += 1

if n == 1:
    print(1)
else:
    print(ans)
