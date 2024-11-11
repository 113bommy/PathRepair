T=int(input())
count=0
s=""
for i in range(T):

    x=input()
    if s=="":
        s=s+x
    else:
        if s[-1] == x[0]:
            count = count
        else:
            count = count + 1
        s = s + x
if count==0:
    print(1)
else:
    print(count)