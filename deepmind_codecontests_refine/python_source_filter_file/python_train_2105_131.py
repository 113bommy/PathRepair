import math
n=int(input())
s=input()
flag1=flag2=0
for i in range(0,n):
    if s[i]=='L':
        flag1+=1
    else:
        flag2+=1
print(flag2+flag2+1)
