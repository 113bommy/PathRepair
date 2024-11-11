n=int(input())
a=input()
b=input()
c=0
for i in range(n):
    x=min(abs(int(a[i])-int(b[i])),10-abs(int(a[i])-int(b[i])))
    c+=x 
print(c)