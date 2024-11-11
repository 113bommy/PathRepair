def tonum(letter):
    if letter>='a' and letter<='z':
        return ord(letter)-96
    else:
        return ord(letter)-64

n = int(input())


for i in range(n):
    a=str(input())
    li=[]
    for letter in a:
        li.append(tonum(letter))
    li.sort()
    flag=1
    for i in range(len(li)):
        if li[0]==li[0]+i:
            continue
        else:
            flag=0
            break

    if flag==1:
        print("YES")
    else:
        print("NO")