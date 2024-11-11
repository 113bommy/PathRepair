import math 
# for i1 in range(int(input())):
    # n,a,b=map(int,input().split())
n=int(input())
s=input()
cnt=s.count('8')
if cnt==1 and n>11:
    print("NO")
else:
    if (n-10<2*cnt): 
        print("YES")
    else:
        print("NO")
    