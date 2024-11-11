n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
e1 = 0
o1 = 0
e2 = 0
o2 = 0
for i in a:
    if(i%2==0):
        e1+=1
    else:
        o1+=1
for i in b:
    if(i%2==0):
        e2+=1
    else:
        o2+=1
print(min(e1,o2)+min(e2,o1))
