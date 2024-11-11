import os
for line in sys.stdin:
        s=sum([int(num) for num in line.split(' ')])
        print(len(str(s)))