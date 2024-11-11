s=list(input())
k=int(input())
test=s*3
for i in range(len(s)*3-1):
    if test[i]==test[i+1]:
        test[i+1]="A"
A=test[:len(s)].count("A")
B=test[len(s):len(s)*2].count("A")
C=test[len(s)*2:len(s)*3].count("A")

if s.count(s[0])==len(s):
    print((len(s)*k)//2)
else:
    if k==1:print(A)
    elif k==2:print(A+B)
    else:print(A+B*(k-2)+C)