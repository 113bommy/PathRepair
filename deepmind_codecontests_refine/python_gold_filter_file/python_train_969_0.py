n=int(input())
s=[int(i) for i in input().split()]
k=0
a=s[0]
b=s[0]
for i in s[1:]:
    if i>a:
        a=i
        k+=1
    if i<b:
        b=i
        k+=1
print(k)