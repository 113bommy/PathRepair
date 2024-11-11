a,b=map(int,input().split())
q=0
w=0
e=0
for i in range (1,7):
    if abs(a-i)<abs(b-i):q+=1;
    if abs(a-i)>abs(b-i):e+=1;
    if abs(a-i)==abs(b-i):w+=1;
print(q, e, w)