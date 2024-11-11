while 1:
 m,f,r=map(int,input().split())
 if m==f==r==-1:break
 if m==-1 or f==-1:print('F')
 elif m+f>79:print('A')
 elif m+f>64:print('B')
 elif m+f>49:print('C')
 elif m+f>29:print('D') if r>49 else print('C')
 else:print('F')