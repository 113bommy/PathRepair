n=int(input())
c=0
for i in range(150000):
    if n%7==0:
        for k in range(c):
            print(4,end='')
        for k in range(n//7):
            print(7,end='')
        break
    n-=4
    c+=1
    if n<0:
        print(-1)
        break