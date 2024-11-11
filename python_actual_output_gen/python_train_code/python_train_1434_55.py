A,B=map(int,input().split())

s=0

while B-(A-1)*s+1>0:
     s+=1
print(s)
