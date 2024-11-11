k=int(input())
print(k+6+(k-1)*2)
for i in range(k+2):
    if i==0:
        print(i,i)
        print(i+1,i)
    elif i!=k+1:
        print(i-1,i)
        print(i,i)
        print(i+1,i)
    else:
        print(i-1,i)
        print(i,i)