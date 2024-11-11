a,b=map(int,input().split());c=[*range(1,a+1)]
for i in map(int,input().split()):c[i-1:a]=[i]*(a-i+1);a=i-1
print(c)