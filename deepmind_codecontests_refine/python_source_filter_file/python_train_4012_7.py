a,b=map(int, input().split())
i=0
while a >0 and b>0 :
    if a <=b:
        a+=1
        b-=2
    else:
        b+=1
        a-=2
    if a >0 and  b>0:
        i+=1
print(i)
