import collections
import itertools
import math
s1 = list(input())
s2 = list(input())

h1 = collections.Counter(s1)
h2 = collections.Counter(s2)

# print(s1, s2)
# print(h1, h2)

flag = False
if '?' not in h2:
    if h1['+'] == h2['+']:
        if h1['-'] == h2['-']:
            flag = True
            print(1)
    
    else:
        print(0)
        
else:
    if flag == False:
        flag1 = False
        for i in h2.keys():
            if i == '?':
                continue
            
            if i not in h1:
                flag1 = True
                break

        if flag1:
            print(0)

        else:
            flag2 = False
            required_plus = required_minus = 0

            if '+' in h2:
                required_plus = h1['+'] - h2['+']
                if required_plus < 0:
                    print(0)
                    flag2 = True
                    
            else:
                required_plus = h1['+']
            
            if flag2 == False:
                if '-' in h2:
                    required_minus = h1['-'] - h2['-']
                else:
                    required_minus = h1['-']

                count = h2['?']
                total = 2**count
                
                # print(required_plus, required_minus)

                if required_plus == 0:
                    num = 1
                if required_minus == 0:
                    num = 1
                
                else:
                    # num = itertools.combinations(count, required_plus)
                    # print(count)
                    # print(required_plus)
                    x = math.factorial(count)
                    y = math.factorial(required_plus)
                    z = math.factorial(count - required_plus)

                    num = x/(y*z)
                # print(num)

                ans = num/total
                print(ans)
