n= int(input())
l=list(map(
    int,input().split(" ")))
l1=[]
n1=1
for i in range (n-1):
    if l[i]>l[i+1]:
        n1+=1
        l1.append(l[i])
l1.append(l[i+1])
print (n1)
print (*l1)
