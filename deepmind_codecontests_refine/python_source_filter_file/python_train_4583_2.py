n,q = map(int,input().split())
A = [list(map(str,input().split())) for i in range(n)]
time = 0
flag = 1
while len(A) > 0:
    if int(A[0][1]) <= q: #プロセスが完了する場合
        time += int(A[0][1])
        print(A[0][1],time)
        del A[0]
    else: #プロセスが完了しない場合
        time += q
        A[0][1] = str(int(A[0][1])-q)
        A.append(A[0])
        del A[0]
