a,b,c,d = map(int,input().split())
print('Yes' if(abs(c-a)<=d or (abs(b-a)<=d and abd(c-b)<=d)) else 'No')