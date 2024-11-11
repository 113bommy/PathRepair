n=int(input())
l=list(map(int,input().split(' ')))
c1,c2=0,0
for i in range(n//2):
    c1=c1+abs((2*i+1)-l[i])
    c2=c2+abs((2*i+2)-l[i])
print(min(c1,c2))
    
