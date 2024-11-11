a=int(input())
b=input().split()
p=0
for i in range(a):
    b[i]=int(b[i])
summin=max(b)
summax=0
for i in range(a):
    if b[i]>summax:
        summax=b[i]
        p=p+1
    if b[i]<summin:
        summin=b[i]
        p=p+1
print(p-2)