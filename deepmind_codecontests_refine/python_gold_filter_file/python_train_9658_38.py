n=int(input())
l=list(map(int,input().split()))
l=l[0::2]
a=0
for i in l:
    if(i%2==1):
        a+=1
print(a)