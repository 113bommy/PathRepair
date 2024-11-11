
t=int(input())
while(t):
    t=t-1
    h,m=map(int,input().split())
    print(((23-h)*60)+59-m+1)