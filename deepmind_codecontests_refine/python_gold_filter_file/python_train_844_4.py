n = int(input())
remain = n%4
if remain == 0:
    print (int(n/4)*'abcd')
if remain == 1:
    print (int(n/4)*'abcd'+'a')
if remain == 2:
    print (int(n/4)*'abcd'+'ab')
if remain == 3:
    print (int(n/4)*'abcd'+'abc')