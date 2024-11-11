a,b,c=map(int,input().split())
e=a-b|b-c
print(len(bin(e&-e))-3or~-e^b&1)