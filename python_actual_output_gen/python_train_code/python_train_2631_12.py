n=input()
s=list(map(str,input().split()))
l=[]
for i in s:
    l.append(tuple(set(i)))
print(len(set(l)))