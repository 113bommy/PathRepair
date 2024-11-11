N = int(input())
ab = sorted([list(map(int,input().split())) for i in range(N)])
diff = {}
for i in range(N-1):
    for j in range(i+1,N):
        a = (ab[i][0]-ab[j][0],ab[i][1]-ab[j][1])
        if a not in diff:
            diff[a] = 1
        else:
            diff[a] += 1
if diff:
    maxv = max(diff.values())
    print(N-maxv)
else:
    print(N)