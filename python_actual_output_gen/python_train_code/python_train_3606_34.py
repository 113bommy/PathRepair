N,A,B,C,D=map(int,input().split())
S=input()

c1=S[B-2:C].count('...')
c2=S[A-1:D].count('##')

if c2>=1:
    print('No')
    exit()
else:
    pass

if C>D and c1==0:
    print('No')
    exit()
else:
    pass


print('Yes')
