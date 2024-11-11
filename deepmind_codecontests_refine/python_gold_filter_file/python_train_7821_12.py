N=int(input())
Sum=0
L=[int(x) for x in input().split()]

Sum+=L[-1]
i=2
x=L[-1]
while i<=N:
    #print(x)
    Sum+=min(L[-i],max(x-1,0))
    x=min(L[-i],max(x-1,0))
    i+=1
print(Sum)