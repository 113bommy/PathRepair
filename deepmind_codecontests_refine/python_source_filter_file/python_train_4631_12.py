from itertools import  *

numbers="9876543210"
x=input()
l= len(x)

st=  1 if x[0]==9 else 0
y=len( x)- st
minx=x
for assignment in product([0,1], repeat=y):
    x2=""
    if st==1:
        x2+=x[0]
    for i in range(st,len(x)):

        x2+=numbers[int(x[i])] if assignment[i-st]==1 else x[i]
    minx=min(x2,minx)
print(minx)
