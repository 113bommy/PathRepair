I=input
for _ in[0]*int(I()):
   n,m=map(int,I().split());k=l=0
   for _ in[0]*n:x=int(I()[::2],2);k+=x<1;l|x
   print('VAisvheiks h'[min(k,m-bin(l).count('1'))%2::2])