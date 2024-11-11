k = int(input())
b=[]
for i in range (0,k):
    n = int(input())
    t=[i for i in input().split()]
    t.sort()
    j=n-1
    p=1
    while int(t[j])>=p and j>=0:
        j-=1
        p+=1
    b.append(p-1)
    
for i in b:
    print(i)
    
