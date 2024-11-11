n, m = [int(i) for i in input().split()]
s = input()

st = [chr(ord('a')+i) for i in range(26)]
for i in range (m) :
    a, b =  input().split()
    for i in range(26):
        if st[i] == a:
            st[i] = b
        elif st[i] == b:
            st[i] = a


print(' '.join([ st[ord(i)-ord('a')] for i in s]))