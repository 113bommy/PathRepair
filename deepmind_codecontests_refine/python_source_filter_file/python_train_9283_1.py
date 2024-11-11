n=int(input())
if n%2==0:
    print("NO")
    exit()
l1=[]
l2=[]
for i in range(2*n):
    if i%4==0 or i%4==3:
        l1.append(i+1)
    else:
        l2.append(i+1)
print("Yes")
print(*(l1+l2))