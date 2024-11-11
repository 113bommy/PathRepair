N, M = map(int, input().split())
s = [list(map(int, input().split())) for i in range(M)]
s.sort(key=lambda x:x[1])

count=1
mae=[0][1]
for i in range(1,N):
    if s[i][0]>=mae:
        count+=1
        maes[i][1]

print(count)