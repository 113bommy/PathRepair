n=int(input())
count=0
h=int(input())
count=h+1
while(n>1):
    n-=1
    h1=int(input())
    if(h>h1):
        count+=h-h1
        h=h1
    count+=1
    count+=h1-h
    count+=1
    h=h1
print(count)
    