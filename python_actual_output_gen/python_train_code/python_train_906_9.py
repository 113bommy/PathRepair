x,s=map(int(input().split()))
n=x+1
a=0
for i in range(n):
    for j in range(n):
        if 0<=s-(i+j)<=x:
            a+=1
print(a)