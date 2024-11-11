n=int(input())
print((n+2)//2)
i=1
j=1
for x in [0]*n:
    print(i,j)
    if x%2==0:
        i+=1
    else:
        j+=1
