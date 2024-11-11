n,m=[int(x) for x in input().split()]
x=[[int(x) for x in input().split()] for _ in range(n)]
a=0
end=1
for i in range(n):
    a+=(max((x[i][0]-end-1)//m,0))*m
    end=x[i][1]
print(x[-1][1]-a)
