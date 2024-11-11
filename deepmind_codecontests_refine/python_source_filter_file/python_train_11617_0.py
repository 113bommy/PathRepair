n = int(input())

s = list(map(int,input().split()))

a = []

for i in range(n):
    a.append(0)

j = n-1

for i in range(n):
    a[s[i]-1]=1
    if a[j] == 1:
        while(j>=0 and a[j]!=0):
            print(j+1,end=' ')
            j-=1
        if j!=0:
            print('\n')
    else:
        print('')
