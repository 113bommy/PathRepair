A,B=map(int,input().split())
print('Possible') if A%3==0or B%3==0or(A+B)%3==0 else print('Impossible')