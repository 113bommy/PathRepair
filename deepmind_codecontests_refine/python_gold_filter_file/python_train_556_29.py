li1=list(map(int, (input()).split()))
li2=list(map(int, (input()).split()))
li3=list(map(int, (input()).split()))
li=[li1]+[li2]+[li3]
for x in range(10**6):
    li[0][0]=x
    a=sum(li[0])
    li[1][1]=a-li[1][0]-li[1][2]
    li[2][2]=a-li[2][0]-li[2][1]
    if (li[0][0]+li[1][1]+li[2][2]==a and
        li[0][2]+li[1][1]+li[2][0]==a and
        sum(li[0])==a and
        sum(li[1])==a and
        sum(li[2])==a and
        li[0][0]+li[1][0]+li[2][0]==a and
        li[0][1]+li[1][1]+li[2][1]==a and
        li[0][2]+li[1][2]+li[2][2]==a):
        print ('''%d %d %d
%d %d %d
%d %d %d''' % (li[0][0],li[0][1],li[0][2],li[1][0],li[1][1],li[1][2],li[2][0],li[2][1],li[2][2]))
        break


