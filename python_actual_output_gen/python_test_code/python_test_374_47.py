n=int(input())
a=input()
a=list(a)
y=[]
b=a.count("z")
c=a.count("o")
for i in range(b):
    y.append("0")
for i in range(abs(b-c)):
    y.append("1")
y=y[::-1]
print(y)
