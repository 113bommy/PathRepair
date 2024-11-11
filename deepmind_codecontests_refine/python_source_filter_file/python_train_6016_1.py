import itertools
 
def check(lis, a):
    return sum((i[3] for i in a if lis[i[1]-1]-lis[i[0]-1]==i[2]))
   
n, m, q = map(int, input().split())
a = ((int(i) for i in input().split(" ")) for j in range(q))
ans = 0
for i in itertools.combinations_with_replacement(range(m), n):
    ans = max(ans, check(i, a))
print(ans)