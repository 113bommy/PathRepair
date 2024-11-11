n = int(input())
mas = list(map(int,input().split()))
print(n+1)
print('1 '+str(n)+' 1000000')
for i,x in enumerate(mas):
    x+=1000000-i-1
    print('2 '+str(i+1)+' '+str(x))