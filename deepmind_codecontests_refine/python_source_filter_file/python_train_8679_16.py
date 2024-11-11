p=int(input())
x=list(map(int,input().split()))
x.sort()
# print(x)


b=[False]*3002
# print(b)

for i in range(p):
    b[x[i]]=True
    
# print(b)

for i in range(1,3001):
    if b[i]==False:
        print(i)
        break