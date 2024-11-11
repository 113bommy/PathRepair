ans = []
cou = 0

while(1):
    n,m = map(int,input().split())
    if(n == 0): break
    ar = list(map(int,input().split()))
    max_ans = 0


    for i in range(n-1):
        for j in range(i,n):
            if(max_ans < ar[i]+ar[j] and ar[i]+ar[j] <= m):
                max_ans = ar[i] + ar[j]

    ans.append(max_ans)
    cou += 1

for i in range(cou):
    if(ans[i] == 0): print("NONE")
    else: print(ans[i])
