a,b,c=map(int,input().split())
e=a-b|c-b
print(len(bin(e&-e))-3or~a%-2)