m=int(input())
a,b=0,0
for i in range(m):
    d,c=[int(j) for j in input().split()]
    a+=d
    b+=c
print(b-1+(a-1)//9)