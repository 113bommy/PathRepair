for i in range(int(input())):
    a,b,c = list(map(int,input().split()))
    ans = []
    if (a < c):
        ans.append(1)
    else:
        ans.append(-1)
    if (c//b < a*b):
        ans.append(b)
    else:
        ans.append(-1)
    print(*ans)