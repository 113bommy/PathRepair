k,d = map(int,input().split())
s = ''
if d==0 and k>1:
    print('No Solution')
elif k==0 :
    print('No Solution')    
else:
    s = str(d)+(k-1)*'0'
    print(s)
