t=int(input())
list1=[]
for i in range(t):
    list1.append([int(x) for x in input().split()])
for i in range(t):
    s=list1[i][0]
    if s%2==0:
        m=(list1[i][1]-1)%4
        if m==0:
            s=s-1-4*((list1[i][1]-1)//4)
        elif m==1:
            s=s-1-4*((list1[i][1]-1)//4)+list1[i][1]
        elif s==2:
            s = s - 1 - 4*((list1[i][1]-1)//4) + 2*list1[i][1]-1
        elif s==3:
            s = s - 1 - 4*((list1[i][1]-1)//4) + list1[i][1]-3
    else:
        m = (list1[i][1] - 1) % 4
        if m == 0:
            s = s + 1 + 4*((list1[i][1]-1)//4)
        elif m == 1:
            s = s + 1 + 4*((list1[i][1]-1)//4) - list1[i][1]
        elif s == 2:
            s = s + 1 + 4*((list1[i][1]-1)//4) - 2 * list1[i][1] + 1
        elif s == 3:
            s = s + 1 + 4*((list1[i][1]-1)//4) - list1[i][1] + 3
    print(s)