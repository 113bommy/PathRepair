n=int(input())
for i in range(n):
    if i%2==0:
        first='W'
        sec='B'
    else:
        first='B'
        sec='W'
    for j in range(n):
        if j%2==0:
            print(first,end=" ")
        else:
            print(sec,end=" ")
    print()

