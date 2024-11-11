s=input()
n=int(input())
l=[]
for x in s:
    l.append(x)
    if x!="1":break
print(l[min(len(l)-1,n)])