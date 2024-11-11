N=int(input())

flag=0
for i in range(int(N^(1//2))+1):
    if N*2==i*(i+1):
        flag=1
        d=i
        break
if flag==0:
    print('No')
    exit(0)

ls=[[0 for _ in range(d)] for _ in range(d+1)]
for i in range(d):
    ls[0][i]=i+1

for j in range(1,d+1):
    for i in range(j):
        ls[j][i]=ls[j-i-1][j-1]
    for i in range(d-j):
        ls[j][i+j]=i+max(ls[j-1])+1
print(ls)
print(d+1)
for i in range(len(ls)):
    print(d, end=' ')
    for j in ls[i]:
        print(j, end=' ')
    print()
