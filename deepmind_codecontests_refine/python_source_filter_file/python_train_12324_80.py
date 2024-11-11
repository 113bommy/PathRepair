n=int(input())
k=1
for i in range(n):
    a=input()
    if(a=="++X" or a=="X++"):
        k+=1
    else:
        k-=1
print(k)