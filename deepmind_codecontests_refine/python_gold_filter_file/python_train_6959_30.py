n=int(input())
a=1
for i in range(1,1+int(n**0.5)):
    if n%i==0:
        a=i
print(max(len(str(a)),len(str(n//a))))