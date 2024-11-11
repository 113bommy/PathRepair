a,b,c=map(int,input().split())
e=b-a|a-c
print((e!=a%2)*(e&-e).bit_length()-1)