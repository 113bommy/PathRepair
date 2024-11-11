# cook your dish here
for _ in range(int(input())):
    h,n,m = map(int,input().split())
    while(h>20 and n>0):
        n-=1
        h//=(1+1)
        h+=10
    while(h>0 and m>0):
        m-=1
        h-=10
    if(h==0):
        print("YES")
    else:
        print("NO")