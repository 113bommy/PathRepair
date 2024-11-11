S=input()[::-1]
n=len(S)
l=list(i for i in range(n) if S[-i]=='B')
k=len(l)*(len(l)-1)//2
print(sum(l)-k)