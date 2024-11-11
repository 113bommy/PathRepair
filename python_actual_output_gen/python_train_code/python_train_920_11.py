n = int(input())
va = [int(x) for x in input().split()]
ga = [0] * 4
for v in va:
    ga[v-1] = ga[v-1] + 1
res = ga[3] + ga[2] + int((ga[1]+1) /2) + max(0, int((ga[0] - ga[2] - 2*(ga[1]%2))/4))
print(res)