n=int(input())
a = list(map(int, input().split()))
k=int(input())
b = list(map(int, input().split()))
##n=5
##a=[1,2,3,4,5]
##k=1
##b=[1]
t=True
d=a+b
for i in a:
    for j in b:
        if not i+j in d:
            print(i,j)
            t=False
            break
        elif i+j in d:
            continue
    if not t:
        break
    

