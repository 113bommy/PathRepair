n,S=input().split(' ')
n=int(n)
S=int(S)
k=0
j=0
if(n>S):
    print("1")
if(n<S):
    while(k<S):
        k=k+n
        j=j+1
print(j)