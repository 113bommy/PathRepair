n=int(input())
*a,=map(int,input().split())
s=0
for i in a:
    s+=1/i
print(1/s)