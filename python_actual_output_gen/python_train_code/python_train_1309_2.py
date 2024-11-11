n = int(input())
for i in range(n):
    if i < n //2:
        w = ((i+1)*2) -1
    else:
        w = ((n- i)*2) -1
    print('{:*^{width}}'.format('C'*w, width=n))