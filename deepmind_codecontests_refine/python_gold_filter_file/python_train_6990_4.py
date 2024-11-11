n, m = map(int, input().strip().split())
arr = []
for i in range(n):
    arr.append(list(map(int, input().strip().split())))

xor = 0
flag = 0
ele = []
for i in range(n):
    seti = set(arr[i])
    if len(seti) > 1 and flag == 0: 
        flag = 1
        ele = [seti.pop(), seti.pop(), i]
    else:
        xor ^= arr[i][0]

if flag == 0 and xor == 0:
    print("NIE")
else:
    print("TAK")
    ans = [1 for i in range(n)]
    if flag == 1:
        ans[ele[2]] = arr[ele[2]].index(ele[0])+1 if xor^ele[0] is not 0 else arr[ele[2]].index(ele[1])+1
    print(*ans)

