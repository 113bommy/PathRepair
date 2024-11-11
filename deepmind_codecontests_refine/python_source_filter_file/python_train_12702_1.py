import itertools as it
    
n = int(input())
A = sorted(list(map(int, input().split())))
q = int(input())
m = list(map(int, input().split()))

s = set()

for i in range(n):
    li= list(it.permutations(A, i+1))
    for j in range(len(li)):
        s.add(sum(li[j]))

for k in range(q):
    print('yes' if m[k] in s else 'no')