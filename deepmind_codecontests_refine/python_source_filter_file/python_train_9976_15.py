x=int(input())
a=1
for i in range(2,11):
    for j in range(1,x+1):
        if j**i<=x:
            a=j**i
print(a)
