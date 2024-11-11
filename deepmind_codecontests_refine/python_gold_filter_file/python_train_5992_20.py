n = input()
n = int(n)
a = input().split()
vis = []
tol = 0
for i in range(n):
    tol += int(a[i])
for i in range(n):
    vis.append(0)
aver = tol//(n//2)
#print(aver)
for i in range(n) :
    for j in range(n) :
        if i <= j:
            continue
        if vis[i] == 0 and vis[j] == 0 :
            if int(a[i]) + int(a[j]) == aver :
                print(str(i+1)+" "+str(j+1))
                vis[i] = 1
                vis[j] = 1