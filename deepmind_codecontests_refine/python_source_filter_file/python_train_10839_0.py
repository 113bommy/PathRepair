#https://codeforces.com/contest/1077/problem/A

#le entrada
n = int(input())
l = []
for i in range(0, n, 1):
    l.append(list(map(int, input().split())))

for i in range(0, n, 1):
    dist = 0
    if(l[i][2] % 2 == 0):
        dist = (l[i][0] - l[i][1])*((l[i][2])/2)
    else:
        dist = l[i][0]
        l[i][2] = l[i][2] - 1
        dist = dist + (l[i][0] - l[i][1])*((l[i][2])/2)
        
    print(int(dist))        
