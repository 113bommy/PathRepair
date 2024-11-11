t=int(input())
for i in range(t):
    cnt=0
    a,b=map(int,input().split())
    if a%b==0:
        print('0')
    else:
        print(b*(a//b+1)-1)
        