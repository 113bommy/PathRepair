s={input()for _ in[0]*int(input().split()[0])}
p=max('','',*(x for x in s if x==x[::-1]),key=len)
t=[x for x in s if x[::-1]in s and x<x[::-1]]
print(len(p)+2*sum(map(len,t)),''.join(t)+p+''.join(x[::-1]for x in t))