n,m=map(int, input().split())
nel=[]
for i in range(n):
    nel.append(input())

for i in range(n):
    if 'B' in nel[i]:
        coun = nel[i].count('B')
        indx = nel[i].index('B')
        break

r = i+coun//2
c= indx + coun//1
print(r+1,c+1)
