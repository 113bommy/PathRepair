a=int(input())
b=sorted(int(input()) for _ in " "*a)
i=0;j=a-1;s=0
while i<=j:
    s+=(2*(b[i]*b[j]))//(1+(i==j))%10007
    i+=1;j-=1
print(s)