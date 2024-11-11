t= int(input())
x= []

for i in range(t):
    l= list(map(int, input().split()))
    x.append(l)
    
for j in range(t):
    x[j].sort(reverse= True)
    if x[j][0]>sum(x[j][1:]):
        print('NO')
    else:
        print('YES')