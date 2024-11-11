a=int(input())
b=0
for i in range(a):
    c,d=map(int,input().split())
    e=c-d
    if(e>=2):
        b+=1
print(b)