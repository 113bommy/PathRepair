n=int(input())
c=0
for i in range(n):
    s=input()
    if(i%2!=1):
        c+=1
    else:
        c-=1
print(c)