x=int(input())
p=input()
s=0
for i in range(x):
    if int(p[i])%2==0:
        s+=i
print(s)

