a=int(input())
x=45*18
for i in range(17):
    x*=10
d=x%a
print(str(a-d)+" "+ str(a-d+1000000000000000000-1))