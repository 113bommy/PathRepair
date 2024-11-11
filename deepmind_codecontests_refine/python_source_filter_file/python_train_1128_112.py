N=int(input())
a=map(int,input().split())
c=0
s=set()
for i in a:
    if i>=3200:
        c+=1
    else:
        s.add(i//400)
print(len(s),len(s)+c)