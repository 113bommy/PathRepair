n=int(input())
l=list(map(int,input().split()))
qo=0
for i in l:
    qo+=i 
print(qo/(n*100))