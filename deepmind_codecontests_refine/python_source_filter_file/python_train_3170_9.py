t = int(input())
l1 = [0,0]
l2 = ["",""]
for x in range(t):
    if x==0:
        l2[0]==input()
        l1[0]=1
    else:
        name = input()
        if name == l2[0]:
            l1[0]+=1
        else:
            if l2[1]=="":
                l2[1]=name
            l1[1]+=1
if l1[0]>l1[1]:
    print(l2[0])
else:
    print(l2[1])