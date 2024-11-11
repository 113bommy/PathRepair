input()
s = input()

def find_divisor(n):
    divisor = []
    for i in range(1,int(n**(1/2))+1):
        if n%i == 0:
            divisor.append(i)
            divisor.append(n//i)
        
    return list(set(divisor))


divisor = find_divisor(len(s))
divisor.sort(reverse=False)

for i in divisor:
    manipulate = s[:i]
    s = manipulate[::-1] + s[i:]
print(s)