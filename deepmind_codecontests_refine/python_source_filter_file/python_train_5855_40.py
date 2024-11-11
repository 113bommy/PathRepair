x=int(input())
i = 2
s=''
while i < x:
    while x%i==0:
        s+=str(i)
        x//=i
    i+=1
print(s)