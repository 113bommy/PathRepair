n=int(input())
s=input()
l=list(s.split(' '))
s=0
for i in l:
    x=int(i)
    s+=x
print(s/(n))