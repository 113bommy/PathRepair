f=lambda:map(int,input().split())
a=int(input())
h=(a//7)*2
print([h,h+1][a%7==6],end=' ')
print(h if a%7==0 else [h+1,h+2][h%7!=1])