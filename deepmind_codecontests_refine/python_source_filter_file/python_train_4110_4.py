a,b,c,d=[int(i) for i in input().split()]
e=(3*a)//10
f=(a-(a//250))*c
g=(3*b)//10
h=(b-(b//250))*d
i=max(f,e)
j=max(g,h)
if(i>j):
    print('Misha')
elif(i==j):
    print("Tie")
else:
    print("Vasya")
