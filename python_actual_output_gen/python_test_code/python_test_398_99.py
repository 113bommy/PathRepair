n=int(input())
A=input().split()
X=0
if n==1:
    if int(A[0])==0:
        print('EASY')
    if int(A[0])==1:
        print('HARD')
else:
    for i in range(0, 3):
        if int(A[i])==1:
            X=1
            break 
    if X==0:
        print('EASY')
    if X==1:
        print('HARD')
