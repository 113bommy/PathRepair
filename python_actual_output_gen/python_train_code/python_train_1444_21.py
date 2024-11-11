t = int(input())
l = []
alphabet = 'abcdefghijkmnopqrstuvwxyz'

for _ in range(t):
    
    n = input()
    s1 = sorted(n)
    s = ''.join(s1)

    if s in alphabet:
        l.append('Yes')
    else:
        l.append('No')

for i in l:
    print(i)