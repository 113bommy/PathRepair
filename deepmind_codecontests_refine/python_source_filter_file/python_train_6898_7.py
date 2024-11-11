t=int(input())

for i in range(t):
    s=input()
    n=len(s)
    arr=[]

    alice=0;
    bob=0

    while len(s)>0:
        start=s.find('1')
        if start==-1: break
        end=s.find('0',start)
        if end==-1:
            arr.append(len(s)-start)
            s=""
        else:
            arr.append(end-start)
            s=s[end+1:]

    
    arr=sorted(arr)
    print(arr)

    if(len(arr)%2==0):
        for j in range(len(arr)):
            if j%2==0:
                bob=bob+arr[j]
            else:
                alice=alice+arr[j]
    else:
        for j in range(len(arr)):
            if j%2==0:
                alice=alice+arr[j]
            else:
                bob=bob+arr[j]

    print(alice)
