from sys import stdin

a=int(stdin.readline())

c=stdin.readline()
print(c)
count=0
count2=0
record=0

for b in range(0,a):

    if c[b]=='(':
        if count<0:
            count2+=1
        count+=1
        if count==0:
            record+=count2
            count2=0
    else:
        count-=1
        if count<0:
            count2+=1

if count!=0:
    print(-1)
else:
    print(record)