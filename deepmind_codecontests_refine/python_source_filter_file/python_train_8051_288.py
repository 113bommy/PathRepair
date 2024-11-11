n=int(input())
a=list(map(int,input().split()))
ratio=0
for i in a:
    if(i>0):
        ratio+=i/100
ratio/=n
ratio*=1000
ratio=round(ratio,11)

print(ratio)
        