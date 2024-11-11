n=int(input())
wordd =[]
for i in range (0,n) :
    ele= input()
    wordd.append(ele)

for x in range (0,n):
    if len(wordd[x]) <10:
        print(wordd[x])
    else:
        print(wordd[x][0] ,(len(wordd[x])-2) ,wordd[x][-1] ,sep='')
