a=int(input())
b=[i for i in range(a)]
c=input().split()
Max=0
Sum=0
for i in range(a):
    b[i]=int(c[i])
for i in range(a):
    if b[i]==0:
        for j in range(a):
            Sum=0
            for k in range(a):
                if k<i or k>j:
                    Sum+=b[k]
                else:
                    Sum+=abs(b[k]-1)
            if Sum>Max:
                Max=Sum
if Max==0:
    print(a)
else:
    print(Max)
