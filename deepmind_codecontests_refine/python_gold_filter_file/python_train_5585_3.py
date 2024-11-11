n, U = list(map(int , input().split()))

E = list(map(int , input().split()))
E.append(10**20)
E.append(10**20)
E.append(10**20)

start = 0
finish = 1
res = -1
while start < n-2:
    while (E[finish] - E[start] >U) and start < n - 2 :
        start += 1
    while (E[finish+1] - E[start] <=U) and (finish+1 < n):
        finish +=1
    # print(start, finish)
    if finish - start >1 and finish<n and start<n:
        if E[finish] - E[start] <=U:
            res = max(res, (E[finish] - E[start+1])/(E[finish]- E[start]))
            # print(start, finish, (E[finish] - E[start+1])/(E[finish]- E[start]))
    start += 1
print(res)