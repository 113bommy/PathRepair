arr=[]
for i in range(1,35):
    arr.append(2**i-1)
temp=[]
for i in arr:
    temp.append(i*(i+1)/2)
res=[temp[0]]
for i in range(1,len(temp)):
    res.append(res[-1]+temp[i])

for _ in range(int(input())):
    n=int(input())
    if n<=6:
        print(1)
    elif 7<=n<=34:
        print(2)
    elif 35<=n<=154:
        print(3)
    else:
        for i in range(len(res)):
            if n<res[i]:
                print(i)
                break