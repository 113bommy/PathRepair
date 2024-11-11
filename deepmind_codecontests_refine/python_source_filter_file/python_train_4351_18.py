X=[list(map(int,input().split()))for i in range(3)]
b=[int(input())for i in range(int(input()))]
for i in range(3):
 X[i]=[1 if i in b else 0 for i in X[i]]
print("Yes" if 3>=max(*[sum(i)for i in X],*[sum([x[i] for x in X])for i in range(3)],X[0][0]+X[1][1]+X[2][2],X[0][2]+X[1][1]+X[2][0]) else "No")