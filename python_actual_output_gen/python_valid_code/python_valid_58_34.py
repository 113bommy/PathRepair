n=int(input())
t=0
for i in range(n):
    s=input()
    if s=='++x' or s=='x++':
        t+=1
    elif s=='x--' or s=='--x':
        t-=1
print(t)