p=list(map(int,input().split()))
t=list(map(int,input().split()))
min=p[0]
for i in range(p[0]):
        if t[i]!=0 and t[i]<=p[2] and abs(p[1]-i)<min:
                min=p[1]-i
                h=i+1
print(abs((h-p[1])*10))

