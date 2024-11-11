N=int(input())
A=list(map(int,input().split()))
Odd,Four=0,0
for a in A:
    if a%2==1:Odd+=1
    elif a%4==0:Four+=1
if Odd+Four==N and Odd-Four==1:print("Yes")
elif Odd<=Four:print("Yes")
else:print("No")