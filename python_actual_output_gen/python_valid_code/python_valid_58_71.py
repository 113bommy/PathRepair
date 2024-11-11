n=int (input())
count=0
for i in range (n):
    s=input()
    if s=='++x' or s=='x++':
        count+=1
    elif s=='--x'or s=='x--':
        count-=1
print(count)

