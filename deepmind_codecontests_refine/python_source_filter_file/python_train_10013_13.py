#Badges
b=int(input())
g=int(input())

n=int(input())

out=0
for i in range(b):
    for j in range(g):
        if (i+j==n):
            out+=1
print(out)