
str = input().split(' ')
n = int(str[0])
m = int(str[0])
i = 0
while(n >0 and m> 0):
    n-=1;
    m-=1;
    i = i+1

if i%2 == 0:
    print("Malvika")
else:
    print("Akshat")
