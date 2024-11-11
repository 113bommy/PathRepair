n = int(input())
it = n//2
n1,n2 = 1,2
A = []
for i in range(n):
    A.append([])
    for j in range(n):
        if j >= it and j <= n-it-1:
            A[i].append(n1)
            n1+=2;
        else:
            A[i].append(n2)
            n2+=2
    if i < n/2-1:
        it-=2
    else:
        it+=2

for i in A:
    for j in i:
        print(j,end = ' ')
    print()
