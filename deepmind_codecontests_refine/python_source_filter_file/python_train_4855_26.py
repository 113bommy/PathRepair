num = int(input())
divisors = [div for div in range(1, int(num/2) + 1) if num % div == 0]
beautifuldiv = [(2**k-1)*2**(k-1) for k in range(1, 9)]

for div in divisors[::-1]:
    if div in beautifuldiv:
        print(div)
        break
