t=int(input())
for _ in range(t):
    a,b,c=map(int,input().split())
    temp=a+b+c
    if(temp%2==0):
        print("1")
    else:
        print("0")