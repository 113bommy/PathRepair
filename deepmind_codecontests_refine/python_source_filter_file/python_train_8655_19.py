s = input()
a_cnt = s.count('a')
if a_cnt > len(s)//2:
    print(0)
else:
    print(2*a_cnt-1)
