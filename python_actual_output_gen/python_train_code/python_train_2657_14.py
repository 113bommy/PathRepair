my_str = input().split()
n, s = int(my_str[0]), int(my_str[1])
cost = []
for i in range(n):
    my_str = input().split()
    cost.append([int(my_str[j]) for j in range(2)])
res = -1
for i in range(n):
    a = s*100-cost[i][0]*100-cost[i][1]
    if a>0 and a%100>res:
        res = a%100
print (res)