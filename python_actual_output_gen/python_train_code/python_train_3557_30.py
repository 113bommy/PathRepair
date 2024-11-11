vals = list()
n,k = map(int, input().split(" "))
joy=-9999999

for i in range(n):
    f,t = map(int, input().split(" "))
    vals.append([f,t])



for j in range(n):
    if vals[j][1] >= k :
       if vals[j][0] - (vals[j][1] - k) >= joy :
           joy = vals[j][0]-(vals[j][1]-k)

    elif vals[j][0] >= joy:
        joy = vals[j][0]

print(joy)


