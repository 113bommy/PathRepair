n = int(input())
if n%2 == 0:
    print("NO")
else:
    print("YES")
    ans = [1]
    for i in range(n-1):
        if i%2 == 0:
            ans.append(ans[-1]+3)
        else:
            ans.append(ans[-1]+1)
    ans.append(2)
    for i in range(n-1):
        if i%2 == 0:
            ans.append(ans[-1]+1)
        else:
            ans.append(ans[-1]+3)
    print(*ans)