a=int(input())
b=int(input())
c=int(input())

li1=[a,b,3*c-a-b]
li2=[4*c-2*a-b,c,2*a+b-2*c]
li3=[a+b-c,2*c-b,2*c-a]
print(*li1)
print(*li2)
print(*li3)