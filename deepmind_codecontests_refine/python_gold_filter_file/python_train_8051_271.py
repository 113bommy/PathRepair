n=int(input())
s=0
b=input().split()
for i in b:
    s=s+(int(i)/100)
print((s/n)*100)