a,b = list(map(int,input().split()))
b = (240-b)//5
s=0
for i in range(1,a+1):
    if b<1 or b<i:
        break
    b-=i
    s+=1
print(s)