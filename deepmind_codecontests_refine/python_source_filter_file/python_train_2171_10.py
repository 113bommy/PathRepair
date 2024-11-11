a,b,c=map(int,input().split())
e=a-b|b-c
print((e^b&1)*(e^e-1).bit_length()-1)