"""
Brandt Smith, Peter Haddad and Lemuel Gorion

Codeforces.com

Problem 169B
"""

a = input()
s = input()

a = [int(x) for x in str(a)]
s = [int(x) for x in str(s)]

s.sort(reverse = True)

final_num = []

for i in range(len(a)):
    m = a[i]
    
    if len(s) != 0:
        n = s[0]
    else:
        n = 0
        
    if n > m:
        temp = n
        s.pop()
    else:
        temp = m
            
    final_num.append(str(temp))


print(''.join(final_num))



    
