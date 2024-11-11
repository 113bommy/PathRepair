n=int(input())
inp=sorted(list(map(int,input().split())))
print(1,inp[0])
if inp[-1]>0:
    print(1,inp[-1])
    print(n-2,end=" ")
    for i in inp[1:n-1]:
        print(i,end=" ")
else:
    print(2,inp[1],inp[2])
    print(n-3,end=" ")
    for i in inp[3:]:
        print(i,end=" ")