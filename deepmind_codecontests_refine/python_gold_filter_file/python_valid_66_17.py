l=[i for i in range(10000) if(i%3!=0)and(i%10)!=3]
t=int(input())
for _ in range(t):
    k=int(input())
    print(l[k-1])