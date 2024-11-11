H,W,K = map(int, input().split())
A = []
d = {'#':1, '.':0}
for i in range(H):
    A.append([d[x] for x in input()])


f=False
t = [0]*W
cnt=1

cnt2 = 0

for i in range(H):
    if f==False:

        if 1 not in A[i]:
            cnt2+=1
        else:
            n=0
            for j in range(W):
                if A[i][j]==1:
                    n+=1
            p = 0

            for j in range(W):
                t[j] = cnt+p

                if A[i][j] == 1:
                    p = min(p+1, n-1)

            for k in range(cnt2+1):
                print(*t)
            cnt2 = 0
            cnt = cnt + n
            if cnt>=K:
                f=True


    else:
        print(*t)
