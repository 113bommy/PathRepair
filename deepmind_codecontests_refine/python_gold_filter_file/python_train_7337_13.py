def solve(k,q):
    if len(set(q)) < k:
        return "NO"
    cs = list(set(q)-{q[0]})[:k-1]
    for c in cs:
        index = q.find(c)
        q = q[:index]+"\n"+q[index:]
    return "YES"+"\n"+q


k = int(input())
q = input()
print(solve(k, q))