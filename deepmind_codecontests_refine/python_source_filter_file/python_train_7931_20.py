q=int(input())
x=[]
for i in range(q):
    a=input()
    y=input().split()
    y=[int(i) for i in y]
    x.append(y)
for i in x:
    for j in range(len(i)):
        if (i[j]+1) in i:
            print(1)
            break
    else:
        print(1)