N, K = map(int,input().split())
li_ = []
for i in range(K):
    d = int(input())
    li_.append(map(int,input().split()))
print(N -len(set(li_)))
