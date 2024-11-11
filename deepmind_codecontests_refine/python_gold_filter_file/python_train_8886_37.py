n=int(input())
k=input()
c=0
for i in range(n-1):
    if k[i]==k[i+1]:
        c=c+1
print(c)