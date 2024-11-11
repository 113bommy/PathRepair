# coding: utf-8
# Your code here!

n=int(input())
S=[]
for i in range(n):
    S.append(input())

a=0

for i in range(n):
    S=[S[-1]]+S[:-1]
#    print(S)
    flag=1
    for j in range(n):
        for k in range(j):
            if S[j][k] != S[k][j]:
                flag=0
                break
    if flag == 1:
        a = a+1

print(a*n)