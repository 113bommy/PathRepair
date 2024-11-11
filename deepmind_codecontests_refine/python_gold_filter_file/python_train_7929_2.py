a=int(input())
A=list(map(int,input().split()))

b=int(input())
B=list(map(int,input().split()))

flag=0

for i in A:
    for j in B:
        if i+j not in A and i+j not in B:
            print(i,j)
            flag=1
            break
    if flag==1:
        break
