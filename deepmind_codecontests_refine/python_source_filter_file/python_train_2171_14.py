a,b,c=map(int,input().split())
e=a-c|c-b
print((e!=c%2)*(e&-e).bit_length()-1)