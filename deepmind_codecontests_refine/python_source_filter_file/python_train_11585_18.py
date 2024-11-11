def read_array():
    x = []
    x1 = []
    x = input()
    x = x.split(' ')
    for r in range(len(x)):
        x1.append(int(x[r]))
    return x1
def find_closer_value(a,b):
    count=0
    if a==b:
        return 0
    if a>b:
        if a>b and (a-10)>b:
            c=(a-b)//10
            if a%10==0:
                count+=c
            else:
                count+=c+1
        else:
            count+=1
    else:
        if a<b and (a+10)<b:
            c=(b-a)//10
            if a%10==0:
                count+=c            
            else:
                count+=c+1
        else:
            count+=1
    return count
res=[]
m=int(input())
for r in range(m):
    x=read_array()
    res.append(find_closer_value(x[0],x[1]))

for v in res:
    print(v)
