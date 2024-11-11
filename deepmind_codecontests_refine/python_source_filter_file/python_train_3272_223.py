n=int(input())
e=[]
s=''
a = input().split()
a.sort()
for i in a:
    s+=str(i + ' ')
print(str(s))