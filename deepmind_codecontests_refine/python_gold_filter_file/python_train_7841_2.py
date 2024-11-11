def primeFact(n):
    ans = []
    i = 3
    num = n

    while n % 2 == 0:
        ans.append(2)
        n = n/2
        

    num = n

    while i * i < num+1:
        while n % i == 0:
        
            ans.append(i)
            n = n / i

        i += 2

    if n > 1: 
        ans.append(int(n))


    return ans


n = int(input())
facts = primeFact(n)
ans = n


for i in facts:
    n = n // i
    ans += n

if len(facts) == 1:
    print(ans)
else: 
    print(ans)
