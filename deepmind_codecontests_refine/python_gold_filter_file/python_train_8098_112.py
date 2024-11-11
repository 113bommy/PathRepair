n=int(input())
k=0
for i in range(n):
    if len(str(i+1))%2==1:
        k+=1
print(k)