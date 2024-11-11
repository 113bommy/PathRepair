n,t=list(map(int,input().split()))
y=list(map(int,input().split()))
lst=[1]
j=1
while j<=len(y):
    j=j+y[j-1]
    lst.append(j)
if t in set(lst):
    print("YES")
else:
    print("NO")
