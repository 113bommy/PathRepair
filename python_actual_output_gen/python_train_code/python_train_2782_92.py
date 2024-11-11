n=int(input())
c=0
for i in range(n):
    if len(str(i))%2==1:
        c+=1
print(c)