l=[]
for j in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=sum(a)
    for i in range(n):
        l+=[[s-a[i],j+1,i+1]]
l.sort()
print(l)
for i in range(len(l)-1):
    if l[i][0]==l[i+1][0]and l[i][1]!=l[i+1][1]:
        exit(print("YES\n",l[i][1],l[i][2],"\n",l[i+1][1],l[i+1][2]))
print("NO")