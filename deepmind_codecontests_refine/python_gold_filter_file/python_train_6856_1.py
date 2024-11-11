import math
N=int(input())
p=math.sqrt(N*2-0.25)-0.5
q=int(p)+1
M=q*(q+1)//2
L=M-N#must0or+
for i in range(1,q+1):
    if i != L:
        print(i)