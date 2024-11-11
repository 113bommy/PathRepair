n=int(input())
x=input()
c=0
y=[0]*(n-3)
for i in range (n-3):
    c=0
    d=ord(x[i])
    c+=min(91-d,d-65)
    d=ord(x[i+3])
    c+=min(abs(71-d),97-d)
    d=ord(x[i+2])
    c+=min(abs(84-d),abs(58-d))
    d=ord(x[i+1])
    c+=min(abs(67-d),93-d)
    y[i]=c
print(min(y))