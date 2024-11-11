tc=int(input())
for test in range(tc):
    A=input()
    x=[]
    count=0
    sol=0
    for i in A:
        if i=='1':
            count+=1
        else:
            x.append(count)
            count=0
    x.append(count)
    x=sorted(x)
    x=x[::-1]
    for i in range(0,len(x),2):
        sol+=x[i]
    print(sol)