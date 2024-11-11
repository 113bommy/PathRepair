n=int(input())
l=[]
for i in range(n):
    l.append(list(map(int,(input().split()))))
remain=0
li=[]
for i in range(len(l)-2):
    enter=l[i][1]
    exit=l[i][0]
    remain=remain+enter-exit
    li.append(remain)
print(max(li))
