m,n=input().split()
m = int(m)
n = int(n)
lis = []
maxx = 0
sat = 0
sot = 0
for i in range(m):
    lis.append(input())
for i in range(m):
    for j in range(n):
        sat = sot = 0
        if lis[i][j] == '0':
            sat = 1
            sot = 1
            ma = 0
            q = 0
            #stoni
            for k in range(i+1, m):
                if lis[k][j] == '0':
                    sot += 1
                    #print(i,j)
                else:break
            p = j+1
            while q == 0 and p < n:
                for k in range(i, m):
                    if lis[k][p] == '1':
                        q = 1
                        break
                if q == 0:
                    p += 1
                    sat += 1
            #print("sat:", sat, "sot:", sot)
            maxx = max(maxx,(sat+sot)*2)
        #satri
            sat = sot = 0
            for k in range(j+1, n):
                if lis[i][k] == '0':
                    sat += 1
                else:break
            q = 0
            p = i + 1
            while q == 0 and p < m:
                for k in range(j, n):
                    if lis[p][k] == '1':
                        q = 1
                        break
                if q == 0:
                    p += 1
                    sot +=q
            maxx = max(maxx,(sat+sot)*2)
print(maxx)
                    
