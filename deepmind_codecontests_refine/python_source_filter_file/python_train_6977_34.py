N=int(input())
l=[[[0 for i in range(10)]for j in range(3)]for k in range(4)]
for i in range(N):
    b, f, r, v = map(lambda x: int(x)-1, input().split())
    l[b][f][r]+=v+1
for j in range(4):
    for k in l[j]:
        print(" ".join(map(str, k)))
    if j < 3:
        print("####################")