n=list(map(int,input()))
for i in range(len(n)):
    if 9>n[i]>4 or (n[i]>4 and len(n)>1): n[i]=9-n[i]
print(''.join(map(str,n)))