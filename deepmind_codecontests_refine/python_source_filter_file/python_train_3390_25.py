n,m=map(int,input().split())
colour={'C','M','Y'}
c_flag=True
for i in range(n):
    temp=list(map(str,input().split()))
    for j in temp:
        if j in colour and c_flag:
            c_flag=False
            print('#Colour')
if c_flag:print('#Black&White')

