N=input()
ans=sum([ (a%2==0 and a%3*a%5 != 0) for a in map(int,input().split()) ])
print(('APPROVED','DENIED')[ans > 0])