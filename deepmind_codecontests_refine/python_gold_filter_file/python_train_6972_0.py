def count_dot(lis):
    c=0
    for i in lis:
        if not(i=='.'):
            return c
        c+=1

def solve(N):
    a=[]
    dot =[]
    for i in range(N):
        a.append([char for char in input()])
        dot.append(count_dot(a[i]))

    for i in range(N):
        for j in range(len(a[i])):
            if a[i][j]=='.':
                a[i][j]=' '

    for i in range(1,N):
        #print(type(dot[i]))
        a[i][dot[i]-1]='+'
        k=1
        while True:
#            print(i-k,dot[i]-1)
            if a[i-k][dot[i]-1] == ' ':
                a[i-k][dot[i]-1]='|'
                k += 1
            else:
                break

    for i in range(N):
        for char in a[i]:
            print(char,end='')
        print()

while True:
    N=int(input())
#    print(N)
    if N==0:
        break
    solve(N)

