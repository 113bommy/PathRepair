"""n=int(input())
c=0
for i in range(n):
    w=input()
    if (w[0]=='1' and w[2]=='1') or (w[0]=='1' and w[4]=='1') or (w[2]=='1' and w[4]=='1'):
        c+=1
print(c)
________________________________________________________
a,b=input().split()
c=0
w=list((input().split()))
#for j in range(len(w)):
for i in w:
    if int(i)>=int(w[int(b)-1]) and int(i)>int(0):
        c+=1


print(c)
_______________________OR_________________________________
p,q=input().split()
x=0
w=list(map(int,input().split()))
for i in w:
    if i>=w[int(q)-1] and i>0:
        x+=1
print(x)
_____________________________________________________
a,b=input().split()
x=int(a)*int(b)
print(x//2)
_______________________________________________________
a=int(input())
c=0
for i in range(a):
    w=input()
    if w=="++X" or w=="X++":
        c+=1
    elif w=="--X" or w=="X--":
        c-=1
print(c)
_____________________________________________________
a=input()
b=input()
if a.lower()==b.lower():
    print("0")
elif a.lower()>b.lower():
    print("1")
elif a.lower()<b.lower():
    print("-1")
____________________________________________________
c=0
for i in range(5):
    a,b,f,d,e=input().split()
    if a=='1' or b=='1' or f=='1' or d=='1' or e=='1':
        c=abs(2-i)
        if a=='1':
            c=c+2
        elif b=='1':
            c=c+1
        elif d=='1':
            c=c+1
        elif e=='1':
            c=c+2
print(c)
_________________________________________________
a=list(map(int,input().split('+')))
a.sort()
for i in range(len(a)):
    if i==len(a)-1:
        print(a[i])
    else:
        print(a[i],end="+")
#_____________________________________________
a=list(input())
print(a[0].upper(),end="")
for i in range(1,len(a)):
    print(a[i],end="")
_______________________________________
a=int(input())
b=list(input())
c=0
for i in range(a-1):
    if b[i] == b[i+1]:
        c+=1
print(c)
#_____________________________________________
a=set(input())
if (len(a)%2) !=0:
    print("IGNORE HIM!")
else:
    print("CHAT WITH HER!")

#_____________________________________________
k,n,w =map(int,input().split())
t=0
for i in range(1,w+1):
    x=k*i
    t=t+x
if (t-n) <=0:
    print('0')
else:
    print(t-n)
#_____________________________________________"""
a,b=map(int,input().split())
for i in range(1,5):
    a=3*a
    b=2*b
    if a>b:
        print(i)
        break





