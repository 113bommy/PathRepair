n=int(input())
l=[int(i) for i in input().split()]
l=[[l[i],i] for i in range(n)]
l.sort(reverse=1) 
a=0 
b=0 
one=[]
two=[]
for i in range(n):
    if i%2==0:
        a+=l[i][0]
        one.append(l[i][1]+1)
    else:
        b+=l[i][0]
        two.append(l[i][1]+1)
print(len(one))
print(*one)
print(len(two))
print(*two)