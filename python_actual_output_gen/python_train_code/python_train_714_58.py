A,V=map(int,input().split())
B,W=map(int,input().split())
T=int(input())
y=abs(B-A)
x=V-W
if x*T-y>0:
    print("YES")
else:

    print("NO")