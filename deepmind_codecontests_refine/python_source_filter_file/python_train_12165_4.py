N,K=map(int, input().split())
S = [list(map(int, input().split())) for i in range(N)]
count=0
for i in S:
    count=count+i[1]
    if count>=K:
        print(i[0])
        break