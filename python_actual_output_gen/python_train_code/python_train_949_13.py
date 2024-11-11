n=int(input())
x=input().split()
x=list(map(int,x))

pos=len([i for i in x if i > 0])
neg=len([i for i in x if i < 0])

if (pos>neg) and (pos >= len(x)/2):
    print(1)

elif (pos<neg) and (neg >= len(x)/2):
    print(-1)

else:
    print(0)