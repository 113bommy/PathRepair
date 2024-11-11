n, ma, mb = [int(i) for i in input().split()]
lst = [[int(i) for i in input().split()] for _ in range(n)]
lst.sort(key=lambda x: x[2])

def push(k,v):
    if k in dic:
        dic[k] = min(dic[k],v)
    else:
        dic[k] = v


for i in lst:
    k, v = i[0] * mb - i[1] * ma, i[2]
    l = [[j, dic[j]] for j in dic]
    for item in l:
        push(item[0] + k, item[1] + v)
    push(k, v)

print(dic[0] if 0 in dic else '-1')