n = int(input())

xl = []

for i in range(n):
    x,l = map(int,input().split())
    xl.append([x+l,x-l])
xl.sort()
ans = -10**10
count = 0
for j in range(n):
    if xl[j][1] >= ans:
        count +=1
        ans = xl[j][0]
print(count)