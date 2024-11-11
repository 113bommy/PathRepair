A,B,C,X,Y=map(int,input().split)
a=A*X+B*Y
b=max(X,Y)*C*2
p=B if X<Y else A
c=min(X,Y)*2*C+abs(X-Y)*p
print(min(a,b,c))