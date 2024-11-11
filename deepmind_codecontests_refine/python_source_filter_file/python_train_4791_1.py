k=' key = '
input()
A=[0]+input().split()
H=len(A)
for i in range(1,H):
 print(f'node {i}: key = {A[i]}, {"parent"+k+A[i//2]+" "if i>1 else""}{"left"+k+A[2*i]+" "if 2*i<H else""}{"right"+A[2*i+1]+" "if 2*i+1<H else""}')
