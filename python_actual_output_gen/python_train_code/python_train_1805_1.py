n= int(input())

s = input()
arr = s.split(' ')

f=0
nmax = 1
for i in range(n-1):
    if int(arr[i+1]) <= int(arr[i])*2:
        f += 1
        if f > nmax : nmax = f
    else : f=1
print(nmax)
