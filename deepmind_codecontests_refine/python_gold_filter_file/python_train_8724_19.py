N,M=[int(i) for i in input().split()]
foods=set(range(1,M+1))
for i in range(N):
    foods=foods&set([int(i) for i in input().split()][1:])
print(len(foods))