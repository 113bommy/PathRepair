a=int(input())
b=int(input())
k=2
if a>b:k=0
elif a<b:k=1
print(('GREATER','LESS','EQUAL')[k])