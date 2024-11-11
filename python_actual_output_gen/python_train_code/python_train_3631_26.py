n, m = map(int, input().split())
ans = []
# a_l = []
# b_l = []
dic = {}

for i in range(m+1):
    if i == m:
        com = list(input().split())
    else:
        a, b = input().split()
        # a_l.append(a)
        # b_l.append(b)
        dic[a] = b

for item in com:
    if len(item) < len(dic[item]):
        print(item, end=" ")
    else:
        print(dic[item], end = " ")
