def divisor(n):
    ass = []
    for i in range(1,int(n**0.5)+1):
        if n%i == 0:
            ass.append(i)
            if i**2 == n:
                continue
            ass.append(n//i)
    return ass

t = int(input())

for testcase in range(t):
    x = int(input())
    print(x//2,x//2)
    

