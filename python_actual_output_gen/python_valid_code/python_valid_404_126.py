n = int(input())
out = 0
for i in range(n):
    v = list(map(int,input().split()))
    if v[1] > v[0]:
        out +=1
print(out)
