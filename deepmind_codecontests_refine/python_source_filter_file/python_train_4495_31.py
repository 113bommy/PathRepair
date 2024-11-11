a=str(input())
s=a.lower()
s1=list(s)
a=""
v=["a","e","i","o","u"]

def diff(s1,v):
    ld= [i for i in v + s1 if i not in v ]
    return ld

result=diff(s1,v)
for j in range(len(result)):
    a=a+"."+str(result[j])
print(a)