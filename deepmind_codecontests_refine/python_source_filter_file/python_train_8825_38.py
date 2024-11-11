A,B=map(int,input().split())
x=-1
for n in range(1000):
    if int(0.08*n)==A and int(0.1*n)==B:
        x=n
        break
print(x)