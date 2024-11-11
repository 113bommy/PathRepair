def process(n, m):
    if n > m:
        return [0, 0]
    n1 = bin(n)[2:]
    m1 = bin(m)[2:]
    n1 = n1.zfill(len(m1))
    n1 = n1[::-1]
    m1 = m1[::-1]
  #  print(n1)
   # print(m1)
   # g = m-n
   # if (n^(g+1))==n+g+1:
   #     return g+1
    answer = 0
    is_good = None
    for i in range(len(m1)):
        if n1[i]=='1' and m1[i]=='0':
            is_good = i
    if is_good is None:
        first_zero = None
        for i in range(len(m1)):
            if m1[i]=='0':
                first_zero = i
                break
        if first_zero is None:
            return [2**(len(m1)), 0]
        answer = 2**(first_zero)
        for i in range(first_zero+1, len(m1)):
            if m1[i]=='1' and n1[i]=='0':
                answer+=(2**i)
        return [answer, 0]
    #so this seems to be fine
    
    for i in range(len(m1)):
        if i > is_good and n1[i]=='0' and m1[i]=='1':
            answer+=(2**i)
    return [answer, 1]

t = int(input())
for i in range(t):
    n, m = [int(x) for x in input().split()]
    print(process(n, m))