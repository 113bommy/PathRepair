n=int(input())
a=list(map(int,input().split()))
j=[0]*n
for i in a:
    j[i-1]+=1
for i in j:
    print(i)