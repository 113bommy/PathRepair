c=int(input())
a=list(map(int,input().split()))
b=list()
for i in range(c):
    b.append(0)
j=0
for i in a:
   b[i-1]=j+1
   j+=1
for i in b:
    print(b,end=" ")