N=int(input())
a=input().split()
A=[int(b) for b in a]

number=A[0]

for n in range(1,N):
    number=number^A[n]

if number==0:
    print('Yes')
else:
    print('No')
    