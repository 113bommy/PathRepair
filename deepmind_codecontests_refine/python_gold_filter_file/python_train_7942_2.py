def answer(n):
    l=int(((2*n)-1)**0.5)
    c=0
    for i in range(3,l+1,2):
        c+=1
    print(c)

t=int(input())
for i in range(t):
    n=int(input())
    answer(n)

