a = int(input())
t=0
for i in range(1,a+1):
    if(t==9):
        break
    for j in range(a):
        if(j%i==0)and(j*i>a)and(j/i<a):
            print(j,end=" ")
            print(i,end=" ")
            t=9
            break
if(t!=9):
    print("-1")