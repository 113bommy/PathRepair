n = int(input().strip())
a = list(map(int, input().split()))
q = int(input().strip())
queries = []
last_balance = [-1]*n
last_balance_id = [-1]*n

for i in range(q):
    query = list(map(int, input().split()))
    queries.append(query)
    if query[0]==1:
        p = query[1]-1
        last_balance[p] = query[2]
        last_balance_id[p] = i


print(last_balance)
print(last_balance_id)

max_pay = [0]*(q+1)
for i in range(q-1,-1,-1):
    query = queries[i]
    if query[0]==2:
        max_pay[i]=max(query[1], max_pay[i+1])
    else:
        max_pay[i]=max_pay[i+1]

print(max_pay)

for p in range(n):
    #print("person: ",p)
    if last_balance_id[p]>=0:
        id = last_balance_id[p]
        pay = max_pay[id]
        print(id, pay)
        a[p] = max(pay, last_balance[p])
    else:
        a[p] = max(a[p], max_pay[0])

print(" ".join([str(x) for x in a]))