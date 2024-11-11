t=int(input())
while t>0:
    n=int(input())
    li=[]
    for i in range(0,n):
        ele=input()
        li.append(ele)
    arr=[]
    for i in range(0,26):
        arr.append(0)
    for ele in li:
        for s in ele:
            o=ord(s)
            index=o%97
            arr[index]+=1
    arr.sort()
    flag=True
    for i in range(25,-1,-1):
        if (arr[i]%n!=0):
            flag=False
            break
    if flag:
        print('true')
    else:
        print('false')
    t=t-1
    