import math
a,b,c= map(int,input().split())
div = []
for i in range(1,a):
    if(a%i==0):
        div.append(i)

for i in div:
    x= a//i
    if(b%i==0 and c//x == b//i):
        print(4*(i+a//i +b//i))
        break

