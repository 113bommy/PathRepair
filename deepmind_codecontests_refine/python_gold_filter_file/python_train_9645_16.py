n=int(input())
a=list(map(int,input().split()))
a=set(a)
val=0
for i in (a):
    if i>0:
        val+=1
print(val)