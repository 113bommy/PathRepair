a,b,c=map(int,input().split())
e=a-b|b-c
print(len(f'{e&-e:b}')-(e==b&1))