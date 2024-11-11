n=int(input())
l=list(map(int,input().split()))
print('PRL'*l[0] + ''.join('R'+i*'PLR' for i in l[1:]))