'''
def IsPrime(N):
    int(N)
    for i in range(2, int(N)):
        if int(N)%i == 0:
            N=0
    if int(N)==1:
        N=0
    return N
m, n = map(int, input().split())
k=0
s=[]
for i in range(m, n+1):
    if IsPrime(i)!=0:
        s+=i
        k+=1
for i in range(len(s)):
    print(s[i])
if k == 0:
    print('Absent')

    
'''
'''
def bin_search(lst, n):
    lenth = len(lst)
    x = 0
    while x!=lenth:
        half = (x+lenth)//2
        if lst[half]==n:
            return n+1


a = [int(s) for s in input('Введите массив:').split()]
elem = int(input('Введите искомый элемент'))
print(bin_search(a, elem))
'''
n = int(input())
a = input()
k=1
r=1
while k<=n:
    print(a[k-1], end='')
    k+=r
    r+=1
    
