input()
n=[0]*100001
for i in map(int,input().split()):
    n[i]+=i
a=b=0
for j in n:
    a,b=max(a,j+b),a
print(a)

