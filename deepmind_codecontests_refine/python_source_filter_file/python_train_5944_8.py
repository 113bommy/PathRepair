#contest thiagohfl

n = input()
n = int(n)

v = [int(i) for i in input().split()]

for i in range(1,len(v)):
    if(v[i]%2==0):
        v[i] = v[i]-1

print(v)