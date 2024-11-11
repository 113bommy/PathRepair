N=int(input())
a=[]
for i in range(1,int(N**(0.5))):
    if N%i==0:
        a.append(max(len(str(i)),len(str(N//i))))
print(min(a))