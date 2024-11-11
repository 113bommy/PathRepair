n=int(input())
list=list(map(int,(input().split())))
m=int(input())
for i in range(m):
    a,b=map(int,input().split())
    if a<n:
        list[a]+=((list[a-1])-b)
    if a>1:
        list[a-2]+=(b-1)
    list[a - 1] = 0
for i in range(len(list)):
    print(list[i])