a=[i for i in range(1700)]
b=[]
for i in range(len(a)):
    if a[i]%3!=0 and a[i]%10!=3:
        b.append(a[i])
T=int(input())
for i in range(T):
    x=int(input())
    print(b[x])