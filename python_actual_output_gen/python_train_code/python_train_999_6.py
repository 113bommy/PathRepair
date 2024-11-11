n=int(input())
list1=list(map(int,input().split()))
c=0
cc=0
for i in range(n):
    if(c==0 or c==1):
        c+=1
        continue
    else:
        if(list1[i]==list1[i-1]+list1[i-2]):
            c+=1
        else:
            if(c>cc):
                cc=c
                c=2
if(c>cc):
    cc=c
print(cc)