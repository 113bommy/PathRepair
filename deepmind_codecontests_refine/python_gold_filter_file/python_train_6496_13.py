n,m=[int(i) for i in input().split()]
A=['1']+input().split()
x=0
for i in range(m):
    if int(A[i+1])>=int(A[i]):
        x+=int(A[i+1])-int(A[i])
    else:
        x+=n+(int(A[i+1])-int(A[i]))
print(x)
