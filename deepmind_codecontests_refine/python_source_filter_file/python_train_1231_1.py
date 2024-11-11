n,h=map(int,input().split())
AB=list(tuple(map(int,input().split())) for i in range(n))
A,B=zip(*AB)
a=max(A)
count=0
for i in sorted(B)[::-1]:
    if i>=a:
        h -=i
        count +=1
    if h<=0:print(count);exit()

print(count+(h//a) if h%a==0 else count+((h+1)//a))