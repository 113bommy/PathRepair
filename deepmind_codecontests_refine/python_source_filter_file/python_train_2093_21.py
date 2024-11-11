"""n,d = input().split()
n = int(n)
d =int(d)
m=int(input())
ans = [False]*m
for i in range(m):
    x,y = list(map(int,input().split()))
    if y>=abs(x-d) and ((x>=(n-d) and y<=(-x+2*n-d)) or (x<(n-d) and y<=(x+d))):
        ans[i] = True
for i in ans:
    if i:
        print("YES")
    else:
        print("NO")"""
import math
n=int(input())
mas = list(map(int,list(input().replace("0",""))))
origin_summa = sum(mas)
summa = origin_summa
found = False

if mas==[] and n>1:
    found = True

split_count = 2
while split_count<=origin_summa and not found:
    while split_count<=summa and summa%split_count!=0:
        split_count+=1
    while summa%split_count==0:
        summa//=split_count    
    split_sum = origin_summa//split_count
    f_ind = 0
    ind =0
    succsess = True
    while f_ind<split_count and succsess==True:
        count = 0
        while ind<n and count<split_sum:
            count+=mas[ind]
            ind+=1
        if count!=split_sum:
            succsess = False
        f_ind+=1
    if summa%split_count==0 and f_ind==split_count and succsess==True:
        found=True
    split_count+=1
if found:
    print("YES")
else:
    print("NO")