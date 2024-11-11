n = int(input())
s = ''
for i in range(n):
        s += " " + input()
se = set(s)
if len(se) <= 26:
        for i in range(97, 123):
                if chr(i) not in se:
                        print(chr(i))
                        exit()
else:
        for i in range(97, 123):
                for j in range(97, 123):
                        if chr(i)+chr(j) not in s:
                                print(chr(i)+chr(j))
                                exit()
                        
