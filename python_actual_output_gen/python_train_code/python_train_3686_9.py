t=int(input())
while t>0:
    st=input().split()
    l2=[]
    for i in st:
        l2.append(int(i))
    l2.sort()
    if l2[0]+l2[1]>=l2[2]:
        print("Yes")
    else:
        print("No")
    t-=1