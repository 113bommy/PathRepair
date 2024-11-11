a,b=map(int,input().split())
mi=min(a,b)
x=int(((a+b)-2*mi)/2)
print(f'{mi} {x}')