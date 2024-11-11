n,k=map(int,input().split());t=input();i=1
while t[i:]!=t[:-i]:i+=1
print(t[:i]*k+t[i:])