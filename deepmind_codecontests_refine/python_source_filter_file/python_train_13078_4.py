n=int(input())
l=[int(i) for i in input().split()]
o=[]
if n==1:
    print("360")
elif n==2:
    print(abs(l[0]-l[1]))
else:
    for i in range(n):
        for j in range(i+1,n):
            k=sum(l[i:j+1])
            o.append(abs(k-180))
    print(2*min(o))