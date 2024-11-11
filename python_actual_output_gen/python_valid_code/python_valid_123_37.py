n=int(input())
x=[]
for i in range(n):
    x.append(list(map(int,input().split())))
k=int(input())
t=False
i+=1
if k==0: print(n)
elif k==x[-1][-1]: print(0)
else:
    for i in range(len(x)):
        if k in range(x[i][0],x[i][1]+1):
            print(n-i)
            break