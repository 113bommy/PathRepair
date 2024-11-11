num=int(input())
alist=list(input().split())
i=0
j=num-1
while alist[i]!=alist[j] and alist[0]!=alist[j] and alist[0]!=alist[i]:
    i+=1
    j-=1
print(j)