n=input()
s=list(map(str,input().split()))
l=[]
for i in s:
    l.append(frozenset(set(i)))
print(len(set(l)))