def swap(x):
    s = len(x)//2
    out = []
    if s>=1:
        for i in range(s):
            out.append([x[i][0],x[-1-i][1]])
            out.append([x[-1-i][0],x[i][1]])
        if len(x)%2==1:
            out.append([x[s][0],x[s][1]])
    else:
        out.append(x[0])
    return out

N, K = map(int, input().split())

if K == 1:
    for i in range(N):
        print(K+i,K+2*N-i-1,K+2*N+i)
elif K <= (N+1)/2:
    ans=[]
    for i in range(N):
        ans.append([K+i,K+2*N-i-1])
    if N%2 == 0:
        s=N//2
        ans_1 = ans[:s+1]
        ans_2 = ans[s+1:-1]
        ans_3 = ans[-1]
        ans_1_new = swap(ans_1)
        ans_2_new = swap(ans_2)
        ans_new = ans_1_new + ans_2_new + ans_3
    else:
        s=(N-1)//2
        ans_1 = ans[:s+1]
        ans_2 = ans[s+1:]
        ans_1_new = swap(ans_1)
        ans_2_new = swap(ans_2)
        ans_new = ans_1_new + ans_2_new
    ans = []
    for elem in ans_new:
        ans.append([elem[0],elem[1],elem[0]+elem[1]])
    ans = sorted(ans, key=lambda x: x[2])
    for i in range(N):
        ans[i][2] = K + 2*N + i
        print(ans[i][0],ans[i][1],ans[i][2])
else:
    print(-1)