n=int(input())
a=list(map(int,input().split()))
ratio=0
for i in a:
    if(i>0):
        ratio+=i/100
ratio/=n
ratio*=100
ratio=round(ratio,1)
print(ratio)
        