n=int(input())
l=list(map(int,input().split()))
l.sort()
for i in range(1,l[n-1]+2):
    if(i not in l):
        print(i)
        break