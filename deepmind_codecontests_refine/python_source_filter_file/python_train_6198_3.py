k = int(input())
q1 = list(map(int,input().split()))
q2 = list(map(int,input().split()))
z = 366
ans = 0
for i in range(1,z+1):
    for j in range(len(q1)):
        if i%q1[j] == q2[j]:
            ans+=1
            break
print(ans/z)