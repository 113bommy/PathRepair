n, k, m = map(int, input().split())
Numbers = list(map(int, input().split()))
Remainder = [0]*m
for i in Numbers:
    temp = i%m
    Remainder[temp]+=1
for i in range(m):
    if Remainder[i]>=k:
        break
else:
    print("no")
    exit()
print("yes")
for j in Numbers:
    if j%m == i:
        print(j,end=" ")
        k-=1
        if k == 0:
            break

