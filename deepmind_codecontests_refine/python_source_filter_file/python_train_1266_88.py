a=[1]
for i in range(1,100):
    a.append(a[-1]+2**(i+1))
x=int(input())
print(a[x-1])
