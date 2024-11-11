x, k = map(int, input().split())
v = [0]*(x+1)
v[0] = 1
v[x] += 1
for i in range(k):
    p = [int(i) for i in input().split()]
    v[p[1]]+=1
    if p[0] == 1:
        v[p[2]]+=1
 
mini, maxi = 10e4,-10e4
flag = False
for i in range(x):
    if v[i] == 0:
        maxi+=1
        if v[i+1] == 0 and not flag:
            mini += 1
            flag = True
        else:
            flag = False
            
print(maxi-mini, maxi)