a=int(input())
d=[]
for i in range(a):
    b=input()
    c=b.split(" ")
    d+=[c]
print(d)
count=0
for i in d:
    if i.count("1")>=2:
        count+=1
print(count)