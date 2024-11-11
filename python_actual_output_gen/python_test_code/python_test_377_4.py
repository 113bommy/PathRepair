from sys import stdin
input=lambda:stdin.readline().strip()
for _ in range(int(input())):
    n,k=[int(i) for i in input().split()]
    lst=[int(i) for i in input().split()]
    lst.sort()
    min1=lst[0]
    nd=0
    lst2=[]
    for i in lst[1:]:
        if i<k:
            nk=(k-i)//min1
            lst2.append(i+(nk)*((k-i)//min1))
            nd+=nk
    if (min(lst2)+min1)<=k:
        nd+=1
    print(nd)
