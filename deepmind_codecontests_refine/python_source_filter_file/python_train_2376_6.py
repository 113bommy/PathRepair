h,w = map(int,input().split())
a = []
for i in range(h):
    ai = list(map(int,input().split()))
    a.append(ai)
ans = []
for i in range(h):
    for j in range(w-1):
        if a[i][j] % 2 == 1:
            ans.append([i+1,j+1,i+1,j+2])
            a[i][j+1] += 1
for i in range(h-1):
    if a[-1][i] % 2 == 1:
        ans.append([i+1,w,i+2,w])
        a[-1][i+1] += 1
print(len(ans))
for i,j,k,l in ans:
    print(i,j,k,l)