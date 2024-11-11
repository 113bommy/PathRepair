for _ in range(int(input())):
    n=int(input())
    arr=[int(i) for i in input().split()]
    s=input()
    l=[]
    for i in range(len(s)):
        l.append([arr[i],int(s[i]),i])
    l.sort()
    dic={0:[],1:[]}
    for i in l:
        dic[i[1]].append(i[2])
    res=[0 for i in range(len(s))]
    c=1
    for i in dic[0]:
        res[i]=c
        c+=1
    for i in dic[1]:
        res[i]=c
        c+=1
    print(res)
    