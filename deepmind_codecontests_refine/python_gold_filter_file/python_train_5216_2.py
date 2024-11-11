n= int(input())

s = input()
arr = s.split(' ')

f=0
nmax = 1
for i in range(n):
    if int(arr[i]) <= int(arr[i-1])*2:
        f += 1
        if f > nmax : nmax = f
    else : f=1
print(nmax)
