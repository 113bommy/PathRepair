n=int(input())
s=input()
a,b=0,0
for i in s:
    if i=="z":
        a=a+1
    if i=="n":
        b=b+1
l=[]
for i in range(0,b):
    l.append("one")
for i in range(0,a):
    l.append("zero")
for i in l:
    print(i,end=" ")