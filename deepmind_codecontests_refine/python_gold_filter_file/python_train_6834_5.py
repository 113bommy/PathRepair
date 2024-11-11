t=int(input())
s=(t//2)*'8'+(t%2)*'4'
if(len(s)<=18):
    print(s)
else:
    print(-1)